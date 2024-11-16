#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <unordered_map>
#include <mutex>
#include "movie_database.h"
#include "user.h"
#include "session_user.h"

class Authentication {
private:
    std::string filename; // Ruta del archivo de usuarios
    std::unordered_map<std::string, std::string> users; // Mapa de usuarios y contraseñas
    MovieDatabase& database; // Instancia de la base de datos de películas
    static std::mutex fileMutex; // Mutex para manejo de acceso a archivo

    void saveUser(const std::string& username, const std::string& password); // Guarda un nuevo usuario

public:
    Authentication();
    
    void loadUsers(); // Carga los usuarios existentes desde el archivo

    // Verifica credenciales de usuario
    bool verifyCredentials(const std::string& username, const std::string& password) const;
    
    // Carga los datos del usuario y los devuelve como SessionUser
    SessionUser loadUserData(const std::string& username, const std::string& password);

    // Guarda los datos actualizados del usuario
    void saveUserData(const User& user);

    // Registra un nuevo usuario
    bool registerUser(const std::string& username, const std::string& password);
};

#endif // AUTHENTICATION_H
