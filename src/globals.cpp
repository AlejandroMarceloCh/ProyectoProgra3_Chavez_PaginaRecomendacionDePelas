//globals.cpp
#include "globals.h"

MovieDatabase& database = MovieDatabase::getInstance();
Authentication auth;
std::unordered_map<std::string, std::unique_ptr<User>> sessions;
std::mutex sessionsMutex;

void set_cors_headers(httplib::Response& res) {
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000");
    res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.set_header("Access-Control-Allow-Headers", "Content-Type, Authorization, Username");
    res.set_header("Access-Control-Allow-Credentials", "true");
}
