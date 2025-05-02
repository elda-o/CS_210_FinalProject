#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class LFUCache {
private:
    unordered_map<string, int> cache;
    unordered_map<string, int> frequency;

    const size_t cache_maxSize = 10;

public:
    void updateCache(const string& key, int population) {
        if (cache.size() >= cache_maxSize) {
            string LFUkey;
            int minFreq = 1000;

            for (const auto& entry : frequency) {
                if (entry.second < minFreq) {
                    minFreq = entry.second;
                    LFUkey = entry.first;
                }
            }

            cache.erase(LFUkey);
            frequency.erase(LFUkey);
        }
        cache[key] = population;
        frequency[key] = 1;
    }

    int searchCache(const string& key) {
        if (cache.count(key)) {
            frequency[key]++;
            return cache[key];
        }
        else {
            return -1;
        }
    }
};