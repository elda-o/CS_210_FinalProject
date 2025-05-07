#include <iostream>
#include <unordered_map>
#include <string>
#include "TrieStruct.h"

using namespace std;

class Trie {
private:

    TrieStruct* root;

public:
    Trie() {
        root = new TrieStruct();
    }

    void insert(const string& city, const string& country, int population) {
        TrieStruct* node = root;

        for (size_t i = 0; i < city.length(); i++) {

            char c = city[i];

            if (!node->elements.count(c)) {
                node->elements[c] = new TrieStruct();
            }

            node = node->elements[c];
        }

        node->end = true;
        node->countryPopulation[country] = population;

    }

    int search(const string& city, const string& country) {
        TrieStruct* node = root;

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