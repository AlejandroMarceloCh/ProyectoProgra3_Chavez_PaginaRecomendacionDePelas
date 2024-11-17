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
