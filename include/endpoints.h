#ifndef ENDPOINTS_H
#define ENDPOINTS_H

#include "httplib.h"
#include "authentication.h"
#include "movie_database.h"
#include "recommendation_system.h"
#include "search_engine.h"
#include "user.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <random>

using json = nlohmann::json;
using namespace httplib;

User& getUserFromSession(const std::string& username);
void handleLogin(const httplib::Request& req, httplib::Response& res);
void handleRegister(const httplib::Request& req, httplib::Response& res);
void handleSearchMovies(const httplib::Request& req, httplib::Response& res);
void handleGetRecommendations(const httplib::Request& req, httplib::Response& res);
void handleGetWatchLater(const httplib::Request& req, httplib::Response& res);
void handleLikeMovie(const httplib::Request& req, httplib::Response& res);
void handleWatchLaterMovie(const httplib::Request& req, httplib::Response& res);

#endif // ENDPOINTS_H



