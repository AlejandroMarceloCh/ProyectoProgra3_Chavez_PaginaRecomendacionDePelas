#include "globals.h"

// Definiciones globales
MovieDatabase& database = MovieDatabase::getInstance();
Authentication auth;
std::unordered_map<std::string, SessionUser> sessions;
std::mutex sessionsMutex;
