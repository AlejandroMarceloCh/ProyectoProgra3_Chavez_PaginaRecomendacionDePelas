#ifndef GLOBALS_H
#define GLOBALS_H

#include "movie_database.h"
#include "authentication.h"
#include "session_user.h"
#include <unordered_map>
#include <mutex>

// Declaraciones globales
extern MovieDatabase& database;
extern Authentication auth;
extern std::unordered_map<std::string, SessionUser> sessions;
extern std::mutex sessionsMutex;

#endif // GLOBALS_H
