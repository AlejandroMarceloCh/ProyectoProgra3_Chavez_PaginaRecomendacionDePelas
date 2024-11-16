#include "search_engine.h"
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include "movie_database.h"

// Constructor que inicializa con una referencia a User
SearchEngine::SearchEngine(const User& user) : user(user) {}

std::string SearchEngine::toLower(const std::string& str) {
    std::string lowercase = str;
    std::transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
    return lowercase;
}


std::vector<std::shared_ptr<Movie>> SearchEngine::search(const std::string& query, int page) {
    std::string lowercaseQuery = toLower(query);
    std::vector<std::shared_ptr<Movie>> combinedResults;

    std::cout << "[DEBUG] Ejecutando búsqueda con query: '" << lowercaseQuery << "'" << std::endl;

    // Obtener instancia de MovieDatabase
    MovieDatabase& database = MovieDatabase::getInstance();

    // Realizar búsquedas en el título
    auto titleResults = database.searchByTitle(lowercaseQuery);
    for (const auto& movie : titleResults) {
        if (movie && !movie->getTitle().empty()) { // Validar puntero y datos
            combinedResults.push_back(movie);
        } else {
            std::cerr << "[ERROR] search: Película con datos inválidos en resultados de título." << std::endl;
        }
    }
    std::cout << "[DEBUG] Resultados por título: " << titleResults.size() << " películas encontradas." << std::endl;

    // Realizar búsquedas en la trama
    auto plotResults = database.searchByPlot(lowercaseQuery);
    for (const auto& movie : plotResults) {
        if (movie && !movie->getPlot().empty()) { // Validar puntero y datos
            combinedResults.push_back(movie);
        } else {
            std::cerr << "[ERROR] search: Película con datos inválidos en resultados de trama." << std::endl;
        }
    }
    std::cout << "[DEBUG] Resultados por trama: " << plotResults.size() << " películas encontradas." << std::endl;

    // Realizar búsquedas en las etiquetas
    auto tagResults = database.searchByTag(lowercaseQuery);
    for (const auto& movie : tagResults) {
        if (movie && !movie->getTags().empty()) { // Validar puntero y datos
            combinedResults.push_back(movie);
        } else {
            std::cerr << "[ERROR] search: Película con datos inválidos en resultados de etiquetas." << std::endl;
        }
    }
    std::cout << "[DEBUG] Resultados por etiquetas: " << tagResults.size() << " películas encontradas." << std::endl;

    // Filtrar duplicados utilizando un unordered_set
    std::unordered_set<std::string> seenMovies;
    auto it = std::remove_if(combinedResults.begin(), combinedResults.end(), [&seenMovies](const auto& movie) {
        if (!movie || seenMovies.count(movie->getId())) {
            return true;
        }
        seenMovies.insert(movie->getId());
        return false;
    });
    combinedResults.erase(it, combinedResults.end());

    std::cout << "[DEBUG] Resultados combinados después de eliminar duplicados: " << combinedResults.size() << std::endl;

    // Limitar los resultados a la página actual
    int RESULTS_PER_PAGE = 6;
    int startIdx = page * RESULTS_PER_PAGE;
    int endIdx = std::min(startIdx + RESULTS_PER_PAGE, static_cast<int>(combinedResults.size()));

    if (startIdx >= static_cast<int>(combinedResults.size())) {
        std::cout << "[DEBUG] No hay suficientes resultados para la página solicitada." << std::endl;
        return {};
    }

    std::cout << "[DEBUG] Retornando resultados desde el índice " << startIdx << " hasta " << endIdx << std::endl;
    return {combinedResults.begin() + startIdx, combinedResults.begin() + endIdx};
}


std::vector<std::shared_ptr<Movie>> SearchEngine::searchForUser(const std::string& query, int page, const User& user) {
    auto results = search(query, page);

    for (auto& movie : results) {
        if (user.hasLiked(movie->getId())) {
            movie->increaseRelevance(10);
        }
        if (user.hasWatchLater(movie->getId())) {
            movie->increaseRelevance(5);
        }
    }

    std::sort(results.begin(), results.end(),
              [](const std::shared_ptr<Movie>& a, const std::shared_ptr<Movie>& b) {
                  return a->getRelevanceScore() > b->getRelevanceScore();
              });

    return results;
}
