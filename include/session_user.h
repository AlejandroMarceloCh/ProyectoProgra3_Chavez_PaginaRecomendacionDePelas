#ifndef SESSION_USER_H
#define SESSION_USER_H

#include "user.h"

class SessionUser {
public:
    // Constructor explícito
    explicit SessionUser(User& user) : user(user) {}

    // Constructor de movimiento
    SessionUser(SessionUser&& other) noexcept : user(other.user) {}

    // Operador de asignación por movimiento
    SessionUser& operator=(SessionUser&& other) noexcept {
        if (this != &other) {
            user = other.user;
        }
        return *this;
    }

    // Métodos para acceder al User
    User& getUser() { return user; }
    const User& getUser() const { return user; }

    // Métodos auxiliares para manipular atributos del User
    std::string getUsername() const { return user.getUsername(); }
    void likeMovie(const std::shared_ptr<Movie>& movie) { user.likeMovie(movie); }
    void addToWatchLater(const std::shared_ptr<Movie>& movie) { user.addToWatchLater(movie); }
    std::vector<std::string> getLikedMoviesIds() const { return user.getLikedMoviesIds(); }
    std::vector<std::string> getWatchLaterIds() const { return user.getWatchLaterIds(); }
    std::vector<std::string> getSearchHistory() const { return user.getSearchHistory(); }

private:
    User& user; // Referencia al Singleton User
};

#endif // SESSION_USER_H
