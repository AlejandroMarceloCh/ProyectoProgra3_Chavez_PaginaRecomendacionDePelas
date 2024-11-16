#ifndef ENDPOINTS_H
#define ENDPOINTS_H

#include "httplib.h"
#include "authentication.h"
#include "movie_database.h"
#include "recommendation_system.h"
#include "search_engine.h"
#include "user.h"
#include "session_user.h"  // Incluir el archivo de SessionUser
#include <nlohmann/json.hpp>
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <random>

using json = nlohmann::json;
using namespace httplib;

// Instancias globales
extern MovieDatabase& database;
extern Authentication auth;
extern std::unordered_map<std::string, SessionUser> sessions;
extern std::mutex sessionsMutex;

// Función auxiliar para generar tokens de sesión únicos
std::string generateSessionToken();

// Función para obtener el usuario de la sesión actual
SessionUser& getUserFromSession(const httplib::Request& req);

// Endpoints de la API
void handleLogin(const httplib::Request& req, httplib::Response& res);
void handleRegister(const httplib::Request& req, httplib::Response& res);
void handleSearchMovies(const httplib::Request& req, httplib::Response& res);
void handleLikeMovie(const httplib::Request& req, httplib::Response& res);
void handleWatchLaterMovie(const httplib::Request& req, httplib::Response& res);
void handleGetRecommendations(const httplib::Request& req, httplib::Response& res);
void handleGetWatchLater(const httplib::Request& req, httplib::Response& res);
void handleGetProfiles(const httplib::Request& req, httplib::Response& res);
#endif // ENDPOINTS_H
