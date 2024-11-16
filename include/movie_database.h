#ifndef MOVIE_DATABASE_H
#define MOVIE_DATABASE_H

#include "movie.h"
#include "trie.h"
#include <nlohmann/json.hpp>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>

using json = nlohmann::json;

class MovieDatabase {
public:
    // Obtener la instancia única del Singleton
    static MovieDatabase& getInstance();

    // Métodos públicos
    void ensureJsonDataAvailable(const std::string& csvFilename, const std::string& jsonFilename);
    bool loadData(const std::string& jsonPath);

    // Métodos de búsqueda
    std::vector<std::shared_ptr<Movie>> searchByTitle(const std::string& title) const;
    std::vector<std::shared_ptr<Movie>> searchByPlot(const std::string& plot) const;
    std::vector<std::shared_ptr<Movie>> searchByTag(const std::string& tag) const;

    // Obtener película por ID
    std::shared_ptr<Movie> getMovieById(const std::string& id) const;


private:
    // Constructor privado
    MovieDatabase();

    // Eliminar copia y movimiento
    MovieDatabase(const MovieDatabase&) = delete;
    MovieDatabase& operator=(const MovieDatabase&) = delete;
    MovieDatabase(MovieDatabase&&) = delete;
    MovieDatabase& operator=(MovieDatabase&&) = delete;

    // Métodos privados
    void convertCsvToJson(const std::string& csvFilename, const std::string& jsonFilename);
    void processMovieData(const json& movieData);
    void workerThread();

    // Datos internos
    std::unordered_map<std::string, std::shared_ptr<Movie>> movies;
    std::shared_ptr<Trie> titleTrie;
    std::shared_ptr<Trie> plotTrie;
    std::shared_ptr<Trie> tagTrie;

    // Hilos y sincronización
    std::vector<std::thread> workers;
    std::queue<json> taskQueue;
    std::mutex queueMutex;
    std::condition_variable queueCondVar;
    bool done = false;

    // Función auxiliar
    std::string cleanString(const std::string& str) const;
};

#endif // MOVIE_DATABASE_H
