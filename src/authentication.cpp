//authentication.cpp
#include "authentication.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "movie_database.h"
#include "user.h"

using json = nlohmann::json;
std::mutex Authentication::fileMutex;

Authentication::Authentication()
    : filename("../data/users.json"), database(MovieDatabase::getInstance()) {
    std::cout << "[DEBUG] Authentication: Inicializando sistema de autenticación..." << std::endl;
    loadUsers();
}

void Authentication::loadUsers() {
    std::ifstream file(filename);
    if (file.is_open()) {
        try {
            json usersJson;
            file >> usersJson;
            file.close();

            for (const auto& [username, userData] : usersJson.items()) {
                users[username] = userData["password"].get<std::string>();
                std::cout << "[DEBUG] Usuario cargado: " << username << " - Contraseña: " << users[username] << std::endl;
            }
        } catch (const json::parse_error& e) {
            std::cerr << "[ERROR] Error al parsear JSON: " << e.what() << std::endl;
        }
    } else {
        std::cerr << "[ERROR] No se pudo abrir el archivo " << filename << std::endl;
    }
}

std::unique_ptr<User> Authentication::loadUserData(const std::string& username, const std::string& password) {
    // Verificar credenciales
    if (!verifyCredentials(username, password)) {
        throw std::runtime_error("[ERROR] Credenciales incorrectas.");
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("[ERROR] No se pudo abrir el archivo de usuarios.");
    }

    json usersJson;
    file >> usersJson;
    auto it = usersJson.find(username);
    if (it != usersJson.end()) {
        json userData = *it;

        // Crear y configurar el objeto User
        auto user = std::make_unique<User>();
        user->setUsername(username);
        user->setPassword(password);
        user->setLikedMoviesIds(userData["liked_movies"].get<std::vector<std::string>>());
        user->setWatchLaterIds(userData["watch_later"].get<std::vector<std::string>>());
        user->setSearchHistory(userData["search_history"].get<std::vector<std::string>>());

        return user; // Retorna un puntero único al objeto User
    }

    throw std::runtime_error("[ERROR] Usuario no encontrado.");
}



bool Authentication::registerUser(const std::string& username, const std::string& password) {
    if (users.find(username) != users.end()) {
        std::cerr << "El usuario ya existe" << std::endl;
        return false;
    }
    users[username] = password;
    saveUser(username, password);
    return true;
}

void Authentication::saveUser(const std::string& username, const std::string& password) {
    std::lock_guard<std::mutex> lock(fileMutex); 

    std::ifstream file(filename);
    json usersJson;
    if (file.is_open()) {
        file >> usersJson;
        file.close();
    }

    usersJson[username] = {
        {"password", password},
        {"liked_movies", json::array()},
        {"watch_later", json::array()},
        {"search_history", json::array()}
    };

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << usersJson.dump(4);
        outFile.close();
    } else {
        std::cerr << "[ERROR] No se pudo abrir el archivo para guardar los datos del usuario." << std::endl;
    }
}

void Authentication::saveUserData(const User& user) {
    std::lock_guard<std::mutex> lock(fileMutex); 

    std::ifstream file(filename);
    json usersJson;
    if (file.is_open()) {
        file >> usersJson;
        file.close();
    }

    usersJson[user.getUsername()] = {
        {"password", user.getPassword()},
        {"liked_movies", user.getLikedMoviesIds()},
        {"watch_later", user.getWatchLaterIds()},
        {"search_history", user.getSearchHistory()}
    };

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << usersJson.dump(4);
        outFile.close();
        std::cout << "[DEBUG] saveUserData: Datos del usuario " << user.getUsername() << " guardados exitosamente." << std::endl;
    } else {
        std::cerr << "[ERROR] No se pudo abrir el archivo para guardar los datos del usuario." << std::endl;
    }
}

bool Authentication::verifyCredentials(const std::string& username, const std::string& password) const {
    auto it = users.find(username);
    bool verified = it != users.end() && it->second == password;
    std::cout << "[DEBUG] verifyCredentials: Usuario " << username 
              << (verified ? " verificado exitosamente." : " no verificado.") << std::endl;
    return verified;
}
