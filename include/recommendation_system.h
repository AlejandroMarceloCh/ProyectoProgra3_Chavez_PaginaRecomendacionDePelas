/*

#ifndef RECOMMENDATION_SYSTEM_H
#define RECOMMENDATION_SYSTEM_H

#include "user.h"
#include "movie.h"
#include <unordered_map>
#include "user.h"  // Incluir el archivo de User
#include "session_user.h"  // Incluir el archivo de SessionUser
#include <vector>
#include <string>
#include <memory>

class RecommendationSystem {
public:
    explicit RecommendationSystem(const User& user) : user(user) {}
    // Método para obtener las recomendaciones mejoradas
    std::vector<std::string> getEnhancedRecommendations();
private:
    // Método para calcular la similitud entre dos películas
    double calculateSimilarity(const Movie& movie1, const Movie& movie2);
    
    // Pesos para las recomendaciones
    static const int LIKED_WEIGHT;
    static const int WATCH_LATER_WEIGHT;
    static const int SEARCH_HISTORY_WEIGHT;
    const User& user; // Referencia al User

};

#endif // RECOMMENDATION_SYSTEM_H
*/

#ifndef RECOMMENDATION_SYSTEM_H
#define RECOMMENDATION_SYSTEM_H

#include "user.h"
#include <vector>
#include <string>

class RecommendationSystem {
public:
    explicit RecommendationSystem(const User& user) : user(user) {}

    // Método para obtener las recomendaciones mejoradas
    std::vector<std::string> getEnhancedRecommendations();

private:
    const User& user;
};

#endif // RECOMMENDATION_SYSTEM_H
