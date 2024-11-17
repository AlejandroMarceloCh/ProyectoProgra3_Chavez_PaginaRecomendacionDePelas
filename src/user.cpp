//user.cpp
#include "user.h"
#include "movie_database.h"
#include <algorithm>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iomanip>
#include <iostream>
#include <memory>
#include <mutex>

using json = nlohmann::json;
const std::string usersFilePath = "../data/users.json";


User::User()
    : username(""), password(""), likedMovies(), watchLater(), searchHistory(), storedRecommendations() {
    std::cout << "[DEBUG] User: Constructor privado llamado." << std::endl;
}

// Mutex para sincronizar accesos al archivo JSON
std::mutex userFileMutex;

void User::setUsername(const std::string& username) {
    this->username = username;
    notifyObservers();
}
void User::setPassword(const std::string& password) {
    this->password = password;
    notifyObservers();
}

std::string User::getUsername() const { return username; }

std::string User::getPassword() const { return password; }

bool User::verifyPassword(const std::string& pass) const { return password == pass; }

// Manejo de recomendaciones
void User::setStoredRecommendations(const std::vector<std::string>& recommendations) {
    storedRecommendations = recommendations;
    notifyObservers();
}

std::vector<std::string> User::getStoredRecommendations() const {
    return storedRecommendations;
}

// Métodos para manejar películas
void User::addToWatchLater(std::shared_ptr<Movie> movie) {
    if (!hasWatchLater(movie->getId())) {
        watchLater.push_back(movie);
        std::cout << "[DEBUG] Película añadida a 'Ver más tarde': " << movie->getTitle() << std::endl;

        // Notificar a los observadores
        notifyObservers();
    }
}



void User::removeFromWatchLater(const std::string& movieId) {
    auto initialSize = watchLater.size();
    watchLater.erase(std::remove_if(watchLater.begin(), watchLater.end(),
                                    [&movieId](const auto& movie) { return movie->getId() == movieId; }),
                     watchLater.end());

    if (watchLater.size() != initialSize) { // Solo notificar si hubo un cambio
        std::cout << "[DEBUG] Película eliminada de 'Ver más tarde': ID " << movieId << std::endl;

        // Notificar a los observadores
        notifyObservers();
    }
}


void User::likeMovie(const std::shared_ptr<Movie>& movie) {
    if (!hasLiked(movie->getId())) {
        likedMovies.push_back(movie->getId());
        std::cout << "[DEBUG] Película añadida a favoritos: " << movie->getTitle() << std::endl;

        // Notificar a los observadores
        notifyObservers();
    }
}


void User::unlikeMovie(const std::string& movieId) {
    auto initialSize = likedMovies.size();
    likedMovies.erase(std::remove_if(likedMovies.begin(), likedMovies.end(),
                                     [&movieId](const std::string& id) { return id == movieId; }),
                      likedMovies.end());

    if (likedMovies.size() != initialSize) { // Solo notificar si hubo un cambio
        std::cout << "[DEBUG] Película eliminada de favoritos: ID " << movieId << std::endl;

        // Notificar a los observadores
        notifyObservers();
    }
}


void User::setLikedMoviesIds(const std::vector<std::string>& likedIds) {
    validateMovieIds(likedIds);
    likedMovies = likedIds;
    std::cout << "[DEBUG] Lista de favoritos actualizada." << std::endl;
    notifyObservers();
}

void User::setWatchLaterIds(const std::vector<std::string>& watchLaterIds) {
    validateMovieIds(watchLaterIds);
    watchLater.clear();
    for (const auto& id : watchLaterIds) {
        watchLater.push_back(std::make_shared<Movie>(id, "", "", std::vector<std::string>{}));
    }
    std::cout << "[DEBUG] Lista de 'Ver más tarde' actualizada." << std::endl;
    notifyObservers();
}

std::vector<std::string> User::getLikedMoviesIds() const { return likedMovies; }

std::vector<std::string> User::getWatchLaterIds() const {
    std::vector<std::string> watchLaterIds;
    for (const auto& movie : watchLater) {
        watchLaterIds.push_back(movie->getId());
    }
    return watchLaterIds;
}



// Manejo del historial de búsqueda
void User::addToSearchHistory(const std::string& query) {
    searchHistory.push_back(query);
    notifyObservers(); // Notificar a los observadores

    // Sincronización con archivo JSON
    std::lock_guard<std::mutex> lock(userFileMutex);

    json userData;
    std::ifstream inFile(usersFilePath);
    if (inFile.is_open()) {
        inFile >> userData;
        inFile.close();
    } else {
        std::cerr << "[ERROR] No se pudo abrir el archivo para lectura: " << usersFilePath << std::endl;
        return;
    }

    userData[username]["search_history"].push_back(query);

    std::ofstream outFile(usersFilePath);
    if (outFile.is_open()) {
        outFile << userData.dump(4);
        outFile.close();
        std::cout << "[DEBUG] Historial actualizado para " << username << ": " << query << std::endl;
    } else {
        std::cerr << "[ERROR] No se pudo abrir el archivo para escritura: " << usersFilePath << std::endl;
    }
}

const std::vector<std::string>& User::getSearchHistory() const { return searchHistory; }

bool User::hasLiked(const std::string& movieId) const {
    return std::find(likedMovies.begin(), likedMovies.end(), movieId) != likedMovies.end();
    notifyObservers();
}

bool User::hasWatchLater(const std::string& movieId) const {
    return std::any_of(watchLater.begin(), watchLater.end(),
                       [&movieId](const auto& movie) { return movie->getId() == movieId; });
    notifyObservers();
}

void User::setSearchHistory(const std::vector<std::string>& history) { searchHistory = history; }

// Validación de IDs de películas
void User::validateMovieIds(const std::vector<std::string>& ids) const {
    MovieDatabase& db = MovieDatabase::getInstance();
    for (const auto& id : ids) {
        if (!db.getMovieById(id)) {
            std::cerr << "[WARNING] ID de película no válida: " << id << std::endl;
        }
    }
}

/*
void User::addObserver(Observer* observer) {
    observers.push_back(observer);
    std::cout << "[DEBUG] Observador añadido. Total de observadores: " << observers.size() << std::endl;
}

void User::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}


void User::notifyObservers() {
    for (auto& observer : observers) {
        observer->update(); // Método definido en Observer
    }
}
*/