#ifndef GLOBALS_H
#define GLOBALS_H

#include "movie_database.h"
#include "authentication.h"
#include "session_user.h"
#include <unordered_map>
#include <mutex>
#include "httplib.h" // Importar httplib solo si es necesario para los CORS

// Declaraciones globales
extern MovieDatabase& database;
extern Authentication auth;
extern std::unordered_map<std::string, SessionUser> sessions;
extern std::mutex sessionsMutex;

// Declaración de la función para configurar CORS
void set_cors_headers(httplib::Response& res);

#endif // GLOBALS_H
