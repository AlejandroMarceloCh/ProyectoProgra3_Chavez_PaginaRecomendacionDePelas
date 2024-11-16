#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
public:
    // Constructor
    Movie(const std::string& id, const std::string& title, const std::string& plot, const std::vector<std::string>& tags);

    // Getters
    std::string getId() const;
    std::string getTitle() const;
    std::string getPlot() const;
    std::vector<std::string> getTags() const;

    // Relevance score
    int getRelevanceScore() const;
    void increaseRelevance(int amount);
    void decreaseRelevance(int amount);

    // Calculate importance based on a query
    void calculateImportance(const std::string& query);

private:
    std::string imdb_id;
    std::string title;
    std::string plot_synopsis;
    std::vector<std::string> tags;
    int relevanceScore;
};

#endif // MOVIE_H
