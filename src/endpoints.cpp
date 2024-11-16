#include "endpoints.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <random>
#include <stdexcept>
#include <mutex>
#include "globals.h"

using json = nlohmann::json;

// Función auxiliar para generar tokens de sesión únicos
std::string generateSessionToken() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    std::string token(32, ' ');
    for (auto& c : token) {
        c = "0123456789abcdef"[dis(gen)];
    }
    return token;
}


// Obtener usuario de sesión
SessionUser& getUserFromSession(const httplib::Request& req) {
    auto cookie = req.get_header_value("Cookie");
    auto sessionToken = cookie.substr(cookie.find("session_token=") + 14);
    {
        std::lock_guard<std::mutex> lock(sessionsMutex);
        auto it = sessions.find(sessionToken);
        if (it != sessions.end()) {
            return it->second;
        } else {
            throw std::runtime_error("[ERROR] Sesión inválida o expirada");
        }
    }
}


// Endpoint para iniciar sesión
void handleLogin(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string username = json_data["username"];
        std::string password = json_data["password"];

        if (!auth.verifyCredentials(username, password)) {
            res.status = 401;
            res.set_content("Credenciales incorrectas", "text/plain");
            return;
        }

        SessionUser user(auth.loadUserData(username, password));
        std::string sessionToken = generateSessionToken();

        {
            std::lock_guard<std::mutex> lock(sessionsMutex);
            sessions.emplace(sessionToken, std::move(user)); // Evitar constructor por defecto
        }

        res.set_header("Set-Cookie", "session_token=" + sessionToken + "; HttpOnly");
        res.set_content("Login exitoso", "text/plain");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleLogin: " << e.what() << std::endl;
        res.status = 500;
        res.set_content("Error interno del servidor", "text/plain");
    }
}

// Endpoint para registrar un nuevo usuario
void handleRegister(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string username = json_data["username"];
        std::string password = json_data["password"];

        if (auth.registerUser(username, password)) {
            res.set_content("Registro exitoso", "text/plain");
        } else {
            res.status = 409;
            res.set_content("Usuario ya existe", "text/plain");
        }
    } catch (...) {
        res.status = 400;
        res.set_content("Error en el formato de la solicitud de registro", "text/plain");
    }
}

// Endpoint para buscar películas
void handleSearchMovies(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string query = json_data["query"];
        int page = json_data.value("page", 0);

        SessionUser& currentUser = getUserFromSession(req);
        currentUser.getUser().addToSearchHistory(query);

        SearchEngine searchEngine(currentUser.getUser());
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
        res.set_content("Error interno del servidor", "text/plain");
    }
}

// Endpoint para dar "me gusta" a una película
void handleLikeMovie(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string movieId = json_data["movieId"];

        SessionUser& currentUser = getUserFromSession(req);
        auto movie = database.getMovieById(movieId);
        if (!movie) {
            res.status = 404;
            res.set_content("Película no encontrada", "text/plain");
            return;
        }

        currentUser.likeMovie(movie);
        auth.saveUserData(currentUser.getUser());
        res.set_content("Película agregada a favoritos", "text/plain");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleLikeMovie: " << e.what() << std::endl;
        res.status = 500;
        res.set_content("Error interno del servidor", "text/plain");
    }
}

// Endpoint para agregar película a "ver más tarde"
void handleWatchLaterMovie(const httplib::Request& req, httplib::Response& res) {
    try {
        auto json_data = json::parse(req.body);
        std::string movieId = json_data["movieId"];

        SessionUser& currentUser = getUserFromSession(req);
        auto movie = database.getMovieById(movieId);
        if (!movie) {
            res.status = 404;
            res.set_content("Película no encontrada", "text/plain");
            return;
        }

        currentUser.addToWatchLater(movie);
        auth.saveUserData(currentUser.getUser());
        res.set_content("Película agregada para ver más tarde", "text/plain");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleWatchLaterMovie: " << e.what() << std::endl;
        res.status = 500;
        res.set_content("Error interno del servidor", "text/plain");
    }
}

// Endpoint para obtener recomendaciones
void handleGetRecommendations(const httplib::Request& req, httplib::Response& res) {
    try {
        SessionUser& currentUser = getUserFromSession(req);
        RecommendationSystem recommendationSystem(currentUser.getUser());

        auto recommendations = recommendationSystem.getEnhancedRecommendations();
        json recommendationsJson = json::array();
        for (const auto& title : recommendations) {
            recommendationsJson.push_back({{"title", title}});
        }

        res.set_content(recommendationsJson.dump(), "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleGetRecommendations: " << e.what() << std::endl;
        res.status = 500;
        res.set_content("Error al obtener recomendaciones", "text/plain");
    }
}



void handleGetProfiles(const httplib::Request& req, httplib::Response& res) {
    try {
        SessionUser& currentUser = getUserFromSession(req);
        json profileJson = {
            {"username", currentUser.getUsername()},
            {"liked_movies", currentUser.getLikedMoviesIds()},
            {"watch_later", currentUser.getWatchLaterIds()},
            {"search_history", currentUser.getSearchHistory()}
        };
        res.set_content(profileJson.dump(), "application/json");
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] handleGetProfiles: " << e.what() << std::endl;
        res.status = 500;
        res.set_content("Error interno del servidor", "text/plain");
    }
}
