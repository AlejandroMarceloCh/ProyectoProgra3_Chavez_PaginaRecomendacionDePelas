// movie.cpp
#include "movie.h"
#include <algorithm>

Movie::Movie(const std::string& id, const std::string& title, const std::string& plot, const std::vector<std::string>& tags)
    : imdb_id(id), title(title), plot_synopsis(plot), tags(tags), relevanceScore(0) {}

std::string Movie::getId() const { return imdb_id; }
std::string Movie::getTitle() const { return title; }
std::string Movie::getPlot() const { return plot_synopsis; }
std::vector<std::string> Movie::getTags() const { return tags; }

int Movie::getRelevanceScore() const { return relevanceScore; }

void Movie::increaseRelevance(int amount) { relevanceScore += amount; }
void Movie::decreaseRelevance(int amount) { relevanceScore = std::max(0, relevanceScore - amount); }


// Implementación de calculateImportance
void Movie::calculateImportance(const std::string& query) {
    std::string lowercaseQuery = query;
    std::transform(lowercaseQuery.begin(), lowercaseQuery.end(), lowercaseQuery.begin(), ::tolower);
    relevanceScore = 0;

    std::string lowercaseTitle = title;
    std::string lowercasePlot = plot_synopsis;

    std::transform(lowercaseTitle.begin(), lowercaseTitle.end(), lowercaseTitle.begin(), ::tolower);
    std::transform(lowercasePlot.begin(), lowercasePlot.end(), lowercasePlot.begin(), ::tolower);

    if (lowercaseTitle.find(lowercaseQuery) != std::string::npos) relevanceScore += 10;
    if (lowercasePlot.find(lowercaseQuery) != std::string::npos) relevanceScore += 5;

    for (const auto& tag : tags) {
        std::string lowercaseTag = tag;
        std::transform(lowercaseTag.begin(), lowercaseTag.end(), lowercaseTag.begin(), ::tolower);
        if (lowercaseTag.find(lowercaseQuery) != std::string::npos) relevanceScore += 3;
    }
}
