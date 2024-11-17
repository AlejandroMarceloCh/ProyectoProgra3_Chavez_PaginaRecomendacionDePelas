//movie_database.cpp
#include "movie_database.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <regex>
#include <algorithm>

using json = nlohmann::json;

// Constructor privado para Singleton
MovieDatabase::MovieDatabase()
    : titleTrie(std::make_shared<Trie>()),
      plotTrie(std::make_shared<Trie>()),
      tagTrie(std::make_shared<Trie>()) {
    const int numThreads = std::thread::hardware_concurrency();
    for (int i = 0; i < numThreads; ++i) {
        workers.emplace_back(&MovieDatabase::workerThread, this);
    }
}

// Método estático para obtener la única instancia del Singleton
MovieDatabase& MovieDatabase::getInstance() {
    static MovieDatabase instance;  // Instancia única
    return instance;
}

std::string MovieDatabase::cleanString(const std::string& str) const {
    std::string result = str;

    // Convertir a minúsculas
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);

    // Eliminar comillas dobles y barras invertidas
    result.erase(std::remove(result.begin(), result.end(), '\\'), result.end());
    result.erase(std::remove(result.begin(), result.end(), '\"'), result.end());

    // Eliminar espacios iniciales y finales
    result.erase(0, result.find_first_not_of(" \t\n\r"));
    result.erase(result.find_last_not_of(" \t\n\r") + 1);

    return result;
}

void MovieDatabase::ensureJsonDataAvailable(const std::string& csvFilename, const std::string& jsonFilename) {
    std::ifstream jsonFile(jsonFilename);
    if (jsonFile.is_open()) {
        jsonFile.close();
        std::cout << "[DEBUG] Archivo JSON ya existe: " << jsonFilename << std::endl;
    } else {
        std::cout << "[DEBUG] Convirtiendo " << csvFilename << " a JSON..." << std::endl;
        convertCsvToJson(csvFilename, jsonFilename);
    }
}

// Implementación de los demás métodos...

void MovieDatabase::workerThread() {
    while (true) {
        json movieData;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            queueCondVar.wait(lock, [this] { return !taskQueue.empty() || done; });

            if (done && taskQueue.empty()) {
                return;
            }

            movieData = std::move(taskQueue.front());
            taskQueue.pop();
        }

        processMovieData(movieData);
    }
}

void MovieDatabase::convertCsvToJson(const std::string& csvFilename, const std::string& jsonFilename) {
    std::ifstream csvFile(csvFilename);
    json jsonArray = json::array();

    if (!csvFile.is_open()) {
        std::cerr << "[ERROR] No se pudo abrir el archivo CSV: " << csvFilename << std::endl;
        return;
    }

    std::string line;
    std::getline(csvFile, line); // Leer y descartar la primera línea (cabecera)
    int movieCount = 0;

    while (std::getline(csvFile, line)) {
        std::stringstream ss(line);
        std::string id, title, plot, tags;

        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, plot, ',');
        std::getline(ss, tags, ',');

        // Limpiar cada campo antes de guardarlo
        id = cleanString(id);
        title = cleanString(title);
        plot = cleanString(plot);

        std::vector<std::string> tagList;
        std::stringstream tagStream(tags);
        std::string tag;
        while (std::getline(tagStream, tag, '|')) {
            tagList.push_back(cleanString(tag));
        }

        // Crear el objeto JSON limpio
        json movieJson = {
            {"id", id},
            {"title", title},
            {"plot", plot},
            {"tags", tagList}
        };

        jsonArray.push_back(movieJson);
        movieCount++;

        std::cout << "[DEBUG] Película procesada (" << movieCount << "): " << title << " (" << id << ")" << std::endl;
    }

    csvFile.close();

    // Guardar el JSON limpio
    std::ofstream jsonFile(jsonFilename);
    if (jsonFile.is_open()) {
        jsonFile << jsonArray.dump(4); // Formato indentado para mayor claridad
        jsonFile.close();
        std::cout << "[DEBUG] Archivo JSON generado exitosamente: " << jsonFilename << std::endl;
    } else {
        std::cerr << "[ERROR] No se pudo abrir el archivo JSON para guardar los datos." << std::endl;
    }
}


bool MovieDatabase::loadData(const std::string& jsonPath) {
    std::ifstream file(jsonPath);
    if (!file.is_open()) {
        std::cerr << "[ERROR] No se pudo abrir el archivo JSON: " << jsonPath << std::endl;
        return false;
    }

    json data;
    file >> data;

    for (const auto& movieData : data) {
        std::string id = cleanString(movieData["id"].get<std::string>());
        std::string title = cleanString(movieData["title"].get<std::string>());
        std::string plot = cleanString(movieData["plot"].get<std::string>());

        std::vector<std::string> tags;
        for (const auto& tag : movieData["tags"]) {
            tags.push_back(cleanString(tag.get<std::string>()));
        }

        auto movie = std::make_shared<Movie>(id, title, plot, tags);
        movies[id] = movie;

        // Inserta datos en los Tries para búsqueda
        titleTrie->insert(title, movie);
        plotTrie->insert(plot, movie);
        for (const auto& tag : tags) {
            tagTrie->insert(tag, movie);
        }
    }

    std::cout << "[DEBUG] Total de películas cargadas: " << movies.size() << std::endl;
    return true;
}


std::shared_ptr<Movie> MovieDatabase::getMovieById(const std::string& id) const {
    auto it = movies.find(id);
    if (it == movies.end()) {
        std::cerr << "[ERROR] getMovieById: Película con ID " << id << " no encontrada." << std::endl;
        return nullptr;
    }
    return it->second;
}


std::vector<std::shared_ptr<Movie>> MovieDatabase::searchByTitle(const std::string& title) const {
    return titleTrie->search(title);
}

std::vector<std::shared_ptr<Movie>> MovieDatabase::searchByPlot(const std::string& plot) const {
    return plotTrie->search(plot);
}

std::vector<std::shared_ptr<Movie>> MovieDatabase::searchByTag(const std::string& tag) const {
    return tagTrie->search(tag);
}

void MovieDatabase::processMovieData(const json& movieData) {
    std::string id = movieData["id"].get<std::string>();
    std::string title = movieData["title"].get<std::string>();
    std::string plot = movieData["plot"].get<std::string>();
    std::vector<std::string> tags = movieData["tags"].get<std::vector<std::string>>();

    auto movie = std::make_shared<Movie>(id, title, plot, tags);
    movies[id] = movie;

    titleTrie->insert(title, movie);
    plotTrie->insert(plot, movie);
    for (const auto& tag : tags) {
        tagTrie->insert(tag, movie);
    }
}