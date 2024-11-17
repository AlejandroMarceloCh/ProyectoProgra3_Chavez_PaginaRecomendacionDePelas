#ifndef RECOMMENDATION_FACTORY_H
#define RECOMMENDATION_FACTORY_H

#include "user.h"
#include "recommendation_system.h"
#include <memory>

class RecommendationFactory {
public:
    static std::unique_ptr<RecommendationSystem> create(const User& user);
};

#endif // RECOMMENDATION_FACTORY_H
