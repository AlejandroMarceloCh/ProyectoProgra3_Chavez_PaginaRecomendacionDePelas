//globals.cpp
#include "globals.h"

MovieDatabase& database = MovieDatabase::getInstance();
Authentication auth;
std::unordered_map<std::string, std::unique_ptr<User>> sessions;
std::mutex sessionsMutex;

void set_cors_headers(httplib::Response& res) {
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000"); // Ajustar para coincidir con tu frontend
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS"); // Métodos permitidos
    res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization, Username"); // Encabezados permitidos
    res.set_header("Access-Control-Allow-Credentials", "true"); // Permitir credenciales (cookies, etc.)
}
