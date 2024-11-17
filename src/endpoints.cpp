#include "endpoints.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <stdexcept>
#include "globals.h"

using json = nlohmann::json;

// Obtener usuario autenticado usando Singleton
User& getUserFromSession() {
    User& user = User::getInstance();
    if (user.getUsername().empty()) {
        throw std::runtime_error("[ERROR] Usuario no autenticado.");
    }
    return user;
}

// Endpoint para iniciar sesión
void handleLogin(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string username = json_data["username"];
        std::string password = json_data["password"];

        if (!auth.verifyCredentials(username, password)) {
            res.status = 401;
            res.set_content(R"({"error": "Credenciales incorrectas"})", "application/json");
            return;
        }

        User& user = User::getInstance();
        user.setUsername(username);
        user.setPassword(password);

        res.set_content(R"({"message": "Login exitoso"})", "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleLogin: " << e.what() << std::endl;
        res.status = 500;
        res.set_content(R"({"error": "Error interno del servidor"})", "application/json");
    }
}

// Endpoint para registrar un usuario
void handleRegister(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string username = json_data["username"];
        std::string password = json_data["password"];

        if (auth.registerUser(username, password)) {
            res.set_content(R"({"message": "Registro exitoso"})", "application/json");
        } else {
            res.status = 409;
            res.set_content(R"({"error": "Usuario ya existe"})", "application/json");
        }
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleRegister: " << e.what() << std::endl;
        res.status = 400;
        res.set_content(R"({"error": "Error en la solicitud de registro"})", "application/json");
    }
}

// Endpoint para buscar películas
void handleSearchMovies(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string query = json_data["query"];
        int page = json_data.value("page", 0);

        User& currentUser = getUserFromSession();
        currentUser.addToSearchHistory(query);

        SearchEngine searchEngine(currentUser);
        auto results = searchEngine.search(query, page);
        json moviesJson = json::array();

        for (const auto& movie : results) {
            moviesJson.push_back({
                {"id", movie->getId()},
                {"title", movie->getTitle()},
                {"plot", movie->getPlot()},
                {"importance_score", movie->getRelevanceScore()}
            });
        }

        res.set_content(moviesJson.dump(), "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleSearchMovies: " << e.what() << std::endl;
        res.status = 401;
        res.set_content(R"({"error": "Usuario no autenticado"})", "application/json");
    }
}

// Endpoint para obtener recomendaciones
void handleGetRecommendations(const httplib::Request& req, httplib::Response& res) {
    try {
        User& currentUser = getUserFromSession();
        RecommendationSystem recommendationSystem(currentUser);

        auto recommendations = recommendationSystem.getEnhancedRecommendations();
        json recommendationsJson = json::array();
        for (const auto& title : recommendations) {
            recommendationsJson.push_back({{"title", title}});
        }

        res.set_content(recommendationsJson.dump(), "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleGetRecommendations: " << e.what() << std::endl;
        res.status = 401;
        res.set_content(R"({"error": "Usuario no autenticado"})", "application/json");
    }
}

void handleGetWatchLater(const httplib::Request& req, httplib::Response& res) {
    try {
        // Obtener el usuario autenticado
        User& currentUser = getUserFromSession();

        // Obtener los IDs de las películas en "Ver más tarde"
        const auto& watchLaterList = currentUser.getWatchLaterIds();

        // Crear un JSON para la respuesta
        json watchLaterJson = json::array();
        for (const auto& movieId : watchLaterList) {
            // Buscar la película por su ID
            auto movie = database.getMovieById(movieId);
            if (movie) {
                // Agregar los datos de la película al JSON
                watchLaterJson.push_back({
                    {"id", movie->getId()},
                    {"title", movie->getTitle()},
                    {"plot", movie->getPlot()},
                    {"tags", movie->getTags()}
                });
            } else {
                std::cerr << "[ERROR] handleGetWatchLater: Película no encontrada para ID " << movieId << std::endl;
            }
        }

        // Enviar la respuesta al cliente
        res.set_content(watchLaterJson.dump(), "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleGetWatchLater: " << e.what() << std::endl;
        res.status = 401; // Responder con 401 si no hay usuario autenticado
        res.set_content(R"({"error": "Usuario no autenticado"})", "application/json");
    }
}
