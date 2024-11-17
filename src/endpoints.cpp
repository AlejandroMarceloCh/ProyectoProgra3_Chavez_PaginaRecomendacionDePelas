#include "endpoints.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <stdexcept>
#include "globals.h"
#include "recommendation_factory.h"

using json = nlohmann::json;

User& getUserFromSession(const std::string& username) {
    std::lock_guard<std::mutex> lock(sessionsMutex);

    auto it = sessions.find(username);
    if (it == sessions.end()) {
        throw std::runtime_error("[ERROR] Usuario no autenticado.");
    }

    return *(it->second); // Desreferencia el unique_ptr para obtener el User
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

        auto user = auth.loadUserData(username, password);
        {
            std::lock_guard<std::mutex> lock(sessionsMutex);
            sessions[username] = std::move(user); // Transfiere la propiedad al mapa de sesiones
        }

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
        std::string username = json_data["username"];

        User& currentUser = *(sessions[username]);
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
        res.status = 500;
        res.set_content(R"({"error": "Error interno del servidor"})", "application/json");
    }
}

// Endpoint para obtener recomendaciones
void handleGetRecommendations(const httplib::Request& req, httplib::Response& res) {
    try {
        std::string username = req.get_header_value("Username");
        User& currentUser = getUserFromSession(req.get_header_value("username"));


        auto recommendationSystem = RecommendationFactory::create(currentUser);
        auto recommendations = recommendationSystem->getEnhancedRecommendations();

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

// Endpoint para obtener la lista "Ver más tarde"
void handleGetWatchLater(const httplib::Request& req, httplib::Response& res) {
    try {
        std::string username = req.get_header_value("Username");
        User& currentUser = getUserFromSession(username);

        const auto& watchLaterList = currentUser.getWatchLaterIds();

        json watchLaterJson = json::array();
        for (const auto& movieId : watchLaterList) {
            auto movie = database.getMovieById(movieId);
            if (movie) {
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

        res.set_content(watchLaterJson.dump(), "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleGetWatchLater: " << e.what() << std::endl;
        res.status = 401;
        res.set_content(R"({"error": "Usuario no autenticado"})", "application/json");
    }
}

// Endpoint para marcar una película como "Me gusta"
void handleLikeMovie(const httplib::Request& req, httplib::Response& res) {
    try {
        std::string username = req.get_header_value("Username");
        User& currentUser = getUserFromSession(username);

        auto json_data = json::parse(req.body);
        std::string movieId = json_data["movieId"];

        auto movie = database.getMovieById(movieId);
        if (!movie) {
            res.status = 404;
            res.set_content(R"({"error": "Película no encontrada"})", "application/json");
            return;
        }

        currentUser.likeMovie(movie);
        auth.saveUserData(currentUser);

        res.set_content(R"({"message": "Película marcada como 'Me gusta'"})", "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleLikeMovie: " << e.what() << std::endl;
        res.status = 500;
        res.set_content(R"({"error": "Error interno del servidor"})", "application/json");
    }
}

// Endpoint para añadir una película a "Ver más tarde"
void handleWatchLaterMovie(const httplib::Request& req, httplib::Response& res) {
    try {
        std::string username = req.get_header_value("Username");
        User& currentUser = getUserFromSession(username);

        auto json_data = json::parse(req.body);
        std::string movieId = json_data["movieId"];

        auto movie = database.getMovieById(movieId);
        if (!movie) {
            res.status = 404;
            res.set_content(R"({"error": "Película no encontrada"})", "application/json");
            return;
        }

        currentUser.addToWatchLater(movie);
        auth.saveUserData(currentUser);

        res.set_content(R"({"message": "Película añadida a 'Ver más tarde'"})", "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleWatchLaterMovie: " << e.what() << std::endl;
        res.status = 500;
        res.set_content(R"({"error": "Error interno del servidor"})", "application/json");
    }
}
