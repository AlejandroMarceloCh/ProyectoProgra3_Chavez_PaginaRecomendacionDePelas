#include "movie_database.h"
#include "authentication.h"
#include "endpoints.h"
#include "globals.h"
#include <httplib.h>
#include <iostream>
#include <csignal>
#include <memory>

// Servidor HTTP
std::unique_ptr<httplib::Server> server_ptr = nullptr;

// Manejo de señales para cerrar el servidor
void signal_handler(int signal) {
    std::cout << "\n[DEBUG] Recibida señal " << signal << ". Cerrando servidor..." << std::endl;
    if (server_ptr) {
        server_ptr->stop();
    }
}

int main() {
    try {
        std::cout << "[DEBUG] Inicializando servidor..." << std::endl;

        // Asegurar que los datos de películas están disponibles y cargar datos
        database.ensureJsonDataAvailable("../data/movies.csv", "../data/movies.json");
        if (!database.loadData("../data/movies.json")) {
            std::cerr << "[ERROR] No se pudo cargar los datos de películas." << std::endl;
            return 1;
        }

        // Cargar usuarios
        auth.loadUsers();

        // Crear el servidor
        server_ptr = std::make_unique<httplib::Server>();

        // Manejo de señales
        signal(SIGINT, signal_handler);
        signal(SIGTERM, signal_handler);

        // Middleware global para agregar encabezados CORS
        server_ptr->set_pre_routing_handler([](const httplib::Request& req, httplib::Response& res) {
            set_cors_headers(res); // Agrega encabezados CORS a todas las respuestas
            if (req.method == "OPTIONS") {
                res.status = 204; // Respuesta para preflight requests
                return httplib::Server::HandlerResponse::Handled;
            }
            return httplib::Server::HandlerResponse::Unhandled;
        });

        // Manejar solicitudes preflight explícitamente (no es estrictamente necesario debido al middleware anterior)
        server_ptr->Options(".*", [](const httplib::Request&, httplib::Response& res) {
            set_cors_headers(res);
            res.status = 204; // No Content
        });

        // Configurar endpoints
        server_ptr->Post("/login", handleLogin);
        server_ptr->Post("/register", handleRegister);
        server_ptr->Post("/search", handleSearchMovies);
        server_ptr->Get("/recommendations", handleGetRecommendations);
        server_ptr->Get("/watchlater", handleGetWatchLater);
        server_ptr->Post("/likeMovie", handleLikeMovie);
        server_ptr->Post("/watchLaterMovie", handleWatchLaterMovie);

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
