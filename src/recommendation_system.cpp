#include "recommendation_system.h"
#include "movie_database.h"
#include <unordered_set>
#include <iostream>

const int LIKED_WEIGHT = 5;
const int WATCH_LATER_WEIGHT = 3;
const int SEARCH_HISTORY_WEIGHT = 1;

std::vector<std::string> RecommendationSystem::getEnhancedRecommendations() {
    MovieDatabase& database = MovieDatabase::getInstance();
    std::unordered_map<std::string, int> movieScores;

    auto likedMovies = user.getLikedMoviesIds();
    auto watchLaterMovies = user.getWatchLaterIds();
    auto searchTerms = user.getSearchHistory();

    for (const auto& likedMovieId : likedMovies) {
        auto movie = database.getMovieById(likedMovieId);
        if (!movie) continue;

        for (const auto& tag : movie->getTags()) {
            auto similarMovies = database.searchByTag(tag);
            for (const auto& similarMovie : similarMovies) {
                if (!user.hasLiked(similarMovie->getId()) && !user.hasWatchLater(similarMovie->getId())) {
                    movieScores[similarMovie->getId()] += LIKED_WEIGHT;
                }
            }
        }
    }

    for (const auto& term : searchTerms) {
        auto searchResults = database.searchByTitle(term);
        for (const auto& result : searchResults) {
            if (!user.hasLiked(result->getId()) && !user.hasWatchLater(result->getId())) {
                movieScores[result->getId()] += SEARCH_HISTORY_WEIGHT;
            }
        }
    }

    std::vector<std::pair<std::string, int>> sortedMovies(movieScores.begin(), movieScores.end());
    std::sort(sortedMovies.begin(), sortedMovies.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::vector<std::string> recommendations;
    for (const auto& moviePair : sortedMovies) {
        auto movie = database.getMovieById(moviePair.first);
        if (movie) {
            recommendations.push_back(movie->getTitle());
            if (recommendations.size() >= 10) break;
        }
    }

    return recommendations;
}
