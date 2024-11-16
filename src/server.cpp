#include "movie_database.h"
#include "authentication.h"
#include "recommendation_system.h"
#include "search_engine.h"
#include "user.h"
#include "session_user.h"
#include "endpoints.h"
#include <httplib.h>
#include <iostream>
#include "globals.h"
#include <csignal>
#include <memory>
#include <unordered_map>
#include <mutex>

// Servidor HTTP
std::unique_ptr<httplib::Server> server_ptr = nullptr;

// Manejo de señales para cierre del servidor
void signal_handler(int signal) {
    std::cout << "\n[DEBUG] Recibida señal " << signal << ". Cerrando servidor..." << std::endl;
    if (server_ptr) {
        server_ptr->stop();
    }
}

// Configuración de CORS
void set_cors_headers(httplib::Response& res) {
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    res.set_header("Access-Control-Allow-Credentials", "true");
}

void cors_middleware(const httplib::Request& req, httplib::Response& res, std::function<void()> next) {
    if (req.method == "OPTIONS") {
        set_cors_headers(res);
        res.status = 204;
        return;
    }
    next();
}

int main() {
    try {
        std::cout << "[DEBUG] Inicializando servidor..." << std::endl;

        // Convertir CSV a JSON si es necesario
        database.ensureJsonDataAvailable("../data/movies.csv", "../data/movies.json");

        // Cargar datos de la base de datos
        if (!database.loadData("../data/movies.json")) {
            std::cerr << "[ERROR] No se pudo cargar los datos de películas." << std::endl;
            return 1;
        }

        // Cargar usuarios
        auth.loadUsers();
        std::cout << "[DEBUG] Sistema de autenticación inicializado." << std::endl;

        // Configurar servidor HTTP
        server_ptr = std::make_unique<httplib::Server>();
        signal(SIGINT, signal_handler);
        signal(SIGTERM, signal_handler);

        // Endpoints
        server_ptr->Post("/login", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /login invocado." << std::endl;
                handleLogin(req, res);
            } catch (const std::exception& e) {
                std::cerr << "[ERROR] Excepción en /login: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        server_ptr->Post("/register", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /register invocado." << std::endl;
                handleRegister(req, res);
            } catch (const std::exception& e) {
                std::cerr << "[ERROR] Excepción en /register: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        server_ptr->Get("/profiles", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /profiles invocado." << std::endl;
                handleGetProfiles(req, res);
            } catch (const std::exception& e) {
                std::cerr << "[ERROR] Excepción en /profiles: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        server_ptr->Post("/search", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /search invocado." << std::endl;

                // Obtener usuario actual desde la sesión
                SessionUser& currentUser = getUserFromSession(req);

                // Crear SearchEngine usando el User de currentUser
                SearchEngine searchEngine(currentUser.getUser());

                // Parsear la solicitud
                auto json_data = json::parse(req.body);
                std::string query = json_data["query"];
                int page = json_data.value("page", 0);

                // Actualizar historial de búsqueda y buscar películas
                currentUser.getUser().addToSearchHistory(query);
                auto results = searchEngine.search(query, page);

                // Preparar respuesta
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
                std::cerr << "[ERROR] /search: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        server_ptr->Post("/like", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /like invocado." << std::endl;
                handleLikeMovie(req, res);
            } catch (const std::exception& e) {
                std::cerr << "[ERROR] /like: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        server_ptr->Post("/watchlater", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /watchlater invocado." << std::endl;
                handleWatchLaterMovie(req, res);
            } catch (const std::exception& e) {
                std::cerr << "[ERROR] /watchlater: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        server_ptr->Get("/recommendations", [](const httplib::Request& req, httplib::Response& res) {
            try {
                std::cout << "[DEBUG] Endpoint /recommendations invocado." << std::endl;

                // Obtener usuario actual desde la sesión
                SessionUser& currentUser = getUserFromSession(req);

                // Crear el sistema de recomendaciones usando el User interno
                RecommendationSystem recommendationSystem(currentUser.getUser());

                // Generar recomendaciones
                auto recommendations = recommendationSystem.getEnhancedRecommendations();

                // Preparar respuesta JSON
                json recommendationsJson = json::array();
                for (const auto& title : recommendations) {
                    recommendationsJson.push_back({{"title", title}});
                }

                res.set_content(recommendationsJson.dump(), "application/json");
            } catch (const std::exception& e) {
                std::cerr << "[ERROR] /recommendations: " << e.what() << std::endl;
                res.status = 500;
                res.set_content("Error interno del servidor", "text/plain");
            }
        });

        std::cout << "[DEBUG] Iniciando servidor en http://127.0.0.1:5050..." << std::endl;
        if (!server_ptr->listen("127.0.0.1", 5050)) {
            std::cerr << "[ERROR] No se pudo iniciar el servidor en el puerto 5050." << std::endl;
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "[ERROR] Excepción en main: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "[DEBUG] Servidor finalizado." << std::endl;
    return 0;
}
