#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include "movie.h"
#include <vector>
#include <string>
#include "user.h"
#include <memory>

class SearchEngine {
public:
    // Constructor que acepta una referencia a User
    explicit SearchEngine(const User& user);

    // Método para realizar la búsqueda por título, trama o etiquetas
    std::vector<std::shared_ptr<Movie>> search(const std::string& query, int page);

    // Método para realizar búsqueda específica ajustada a un usuario
    std::vector<std::shared_ptr<Movie>> searchForUser(const std::string& query, int page, const User& user);

private:
    // Función para convertir una cadena a minúsculas
    std::string toLower(const std::string& str);

    // Referencia constante al User
    const User& user;
};

#endif // SEARCH_ENGINE_H
