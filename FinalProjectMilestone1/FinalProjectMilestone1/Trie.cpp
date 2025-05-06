#include <iostream>
#include <unordered_map>
#include <string>
#include "TrieStruct.cpp"

using namespace std;

class Trie {
private:

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& city, const string& country, int population) {
        TrieNode* node = root;

        for (size_t i = 0; i < city.length(); i++) {

            char c = city[i];

            if (!node->elements.count(c)) {
                node->elements[c] = new TrieNode();
            }
        }

        node->end = true;
        node->countryPopulation[country] = population;

    }

    int search(const string& city, const string& country) {
        TrieNode* node = root;

        for (size_t i = 0; i < city.length(); i++) {

            char c = city[i];

            if (!node->elements.count(c)) {
                return -1;
            }

            node = node->elements[c];
        }

        if (node->end && node->countryPopulation.count(country)) {
            
            return node->countryPopulation[country];
        }

        return -1;
    }
};