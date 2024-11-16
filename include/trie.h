#pragma once

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "movie.h"

// Nodo del Trie
class TrieNode {
public:
    // Constructor
    TrieNode();

    // Indica si el nodo representa el final de una palabra
    bool isEndOfWord;

    // Películas asociadas a este nodo
    std::vector<std::shared_ptr<Movie>> movies;

    // Hijos del nodo
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
};

// Estructura Trie
class Trie {
public:
    // Constructor
    Trie();

    // Inserta una palabra y asocia una película
    void insert(const std::string& word, std::shared_ptr<Movie> movie);

    // Busca películas basadas en un prefijo
    std::vector<std::shared_ptr<Movie>> search(const std::string& word);

private:
    // Nodo raíz del Trie
    std::shared_ptr<TrieNode> root;
};

