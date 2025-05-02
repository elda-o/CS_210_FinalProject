#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <list>

using namespace std;

class RandomReplacementCache {
private:
    unordered_map<string, int> cache;
    list<string> keys;
    const size_t cache_maxSize = 10;

public:
    void updateCache(const string& key, int population) {
        if (cache.size() >= cache_maxSize) {
            string removedKey = keys.front();
            keys.pop_front();
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