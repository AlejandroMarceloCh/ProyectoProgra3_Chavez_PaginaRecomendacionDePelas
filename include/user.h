#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include "observer.h"

class Movie;

class User : public Subject {
public:
    User(); // Constructor público

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    std::string getUsername() const;
    std::string getPassword() const;

    bool verifyPassword(const std::string& pass) const;
    void setStoredRecommendations(const std::vector<std::string>& recommendations);
    std::vector<std::string> getStoredRecommendations() const;

    // Métodos para manejar películas
    void addToWatchLater(std::shared_ptr<Movie> movie);
    void removeFromWatchLater(const std::string& movieId);
    void likeMovie(const std::shared_ptr<Movie>& movie);
    void unlikeMovie(const std::string& movieId);
    void setLikedMoviesIds(const std::vector<std::string>& likedIds);
    void setWatchLaterIds(const std::vector<std::string>& watchLaterIds);
    std::vector<std::string> getLikedMoviesIds() const;
    std::vector<std::string> getWatchLaterIds() const;

    // Manejo del historial de búsqueda
    void addToSearchHistory(const std::string& query);
    const std::vector<std::string>& getSearchHistory() const;
    void setSearchHistory(const std::vector<std::string>& history);

    bool hasLiked(const std::string& movieId) const;
    bool hasWatchLater(const std::string& movieId) const;

private:
    void validateMovieIds(const std::vector<std::string>& ids) const;

    std::string username;
    std::string password;
    std::vector<std::string> likedMovies;
    std::vector<std::shared_ptr<Movie>> watchLater;
    std::vector<std::string> searchHistory;
    std::vector<std::string> storedRecommendations;
};

#endif // USER_H
