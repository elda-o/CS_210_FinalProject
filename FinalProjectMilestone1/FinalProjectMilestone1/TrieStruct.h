#ifndef TRIESTRUCT_H
#define TRIESTRUCT_H

#pragma once
#include <string>
#include <unordered_map>


using namespace std;

struct TrieStruct {
    unordered_map<char, TrieStruct*> elements;
    unordered_map<string, int> countryPopulation;
    bool end = false;
};

#endif // TRIESTRUCT_H
