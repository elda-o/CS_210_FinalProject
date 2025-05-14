#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "CityLookup.cpp"
#include "CSVReader.cpp"

using namespace std;
using namespace std::chrono;

int lookups = 1000;

void loadTest(int cacheChoice, Trie& trie, const string& fileName, const vector<vector<string>>& cityData) {

    CityLookup cityLookup(cacheChoice, &trie);
    vector<string> queries;
    vector<bool> cache;
    vector<double> lookupTimes;

    for (int i = 0; i < lookups; i++) {

        int index = rand() % cityData.size();

        string country = cityData[index][0];
        string city = cityData[index][1];


        queries.push_back(country + "," + city);

    }

    auto startTime = high_resolution_clock::now();

    for (const auto& query : queries) {

        string country = query.substr(0, query.find(","));
        string city = query.substr(query.find(",") + 1);

        auto lookupStart = high_resolution_clock::now();
        int population = cityLookup.searchCache(fileName, country, city);
        auto lookupEnd = high_resolution_clock::now();

        double lookupDuration = duration<double, milli>(lookupEnd - lookupStart).count();

        lookupTimes.push_back(lookupDuration);
        cache.push_back(population != -1);

    }

    auto endTime = high_resolution_clock::now();

    double totalTime = duration<double, milli>(endTime - startTime).count();
    double averageTime = totalTime / lookups;
    int cacheHitCount = count(cache.begin(), cache.end(), true);

    cout << "Cache Strategy: ";

    if (cacheChoice == 1) {
        cout << "FIFO";
    }
    else if (cacheChoice == 2) {
        cout << "LFU";
    }
    else if (cacheChoice == 3){
        cout << "Random Replacement";
    }
    else {
        cout << "Invalid cache choice";
    }

    cout << endl;
    cout << "Total Queries: " << lookups << endl;
    cout << "Total Time: " << totalTime << " ms" << endl;
    cout << "Average Lookup Time: " << averageTime << " ms" << endl;
    cout << "Cache Hits: " << cacheHitCount << " / " << lookups << endl;
    cout << "Cache Hit Rate: " << (cacheHitCount * 100.0 / lookups) << "%" << endl;
}

int main() {
    string fileName = "world_cities.csv";
    Trie trie;

    CSVReader::TrieData(fileName, trie);

    vector<vector<string>> cityData = CSVReader::readCSV(fileName);
    if (cityData.empty()) {
        cerr << "Error: No city data found in CSV file." << endl;
        return 1;
    }

    for (int cacheChoice = 1; cacheChoice <= 3; cacheChoice++) {
        loadTest(cacheChoice, trie, fileName, cityData);
    }

    return 0;
}
