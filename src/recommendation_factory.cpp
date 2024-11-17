#include "recommendation_factory.h"

// Implementación de la fábrica
std::unique_ptr<RecommendationSystem> RecommendationFactory::create(const User& user) {
    return std::make_unique<RecommendationSystem>(user);
}
