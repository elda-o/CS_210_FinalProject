#include <iostream>
#include <string>
#include<unordered_map>
#include <deque>
#include "CSVReader.cpp"

using namespace std;

class CityLookup {
private:
    unordered_map<string, int> cache;
    deque<string> latest;
    const size_t cache_maxSize = 10;

public:
    void updateCache(const string& key, int population) {
        if (cache.size() >= cache_maxSize) {
            string oldest = latest.front();
            latest.pop_front();
            cache.erase(oldest);
        }

        cache[key] = population;
        latest.push_back(key);
    }

    int searchCache(const string& fileName, const string& country, const string& city) {

        string s = country + "," + city;

        if (cache.find(s) != cache.end()) {
            cout << "Cache: " << s << " population: " << cache[s] << endl;
            return cache[s];
        }

        CityStruct cityStruct = CSVReader::searchCity(fileName, country, city);

        if (cityStruct.population > -1) {
            updateCache(s, cityStruct.population);
            return cityStruct.population;
        }

        return -1; //if not found

    }
};