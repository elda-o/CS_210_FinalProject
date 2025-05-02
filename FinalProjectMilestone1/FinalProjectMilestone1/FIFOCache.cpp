#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class FIFOCache {
private:
    unordered_map<string, int> cache;
    queue<string> order;
    const size_t max = 10;

public:
    void updateCache(const string& key, int population) {
        if (cache.size() >= max) {
            string oldest = order.front();
            order.pop();
            cache.erase(oldest);
        }
        cache[key] = population;
        order.push(key);
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