#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class RandomReplacementCache {
private:
    unordered_map<string, int> cache;
    vector<string> keys;
    const size_t cache_maxSize = 10;

public:
    void updateCache(const string& key, int population) {
        if (cache.size() >= cache_maxSize) {
            int index = rand() % keys.size();
            string removedKey = keys[index];
            keys.erase(keys.begin() + index);
            cache.erase(removedKey);
        }
        cache[key] = population;
        keys.push_back(key);
    }

    int searchCache(const string& key) {
        if (cache.count(key)) {
            return cache[key];
        }
        else {
            return -1;
        }
    }
};