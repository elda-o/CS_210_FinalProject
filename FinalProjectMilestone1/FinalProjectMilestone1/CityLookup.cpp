#include <iostream>
#include <string>
#include<unordered_map>
#include <deque>
#include "CSVReader.cpp"
#include "FIFOCache.cpp"
#include "LFUCache.cpp"
#include "RandomReplacementCache.cpp"
#include "Trie.cpp"

using namespace std;

class CityLookup {
private:
    FIFOCache* fifoCache = nullptr;
    LFUCache* lfuCache = nullptr;
    RandomReplacementCache* randomReplacementCache = nullptr;
    Trie* trie;
    int chosenCache = 0;
//    from previous milestone
//    unordered_map<string, int> cache;
//    deque<string> latest;
//    const size_t cache_maxSize = 10;

public:
    //from previous milestone
   /* void updateCache(const string& key, int population) {
        if (cache.size() >= cache_maxSize) {
            string oldest = latest.front();
            latest.pop_front();
            cache.erase(oldest);
        }

        cache[key] = population;
        latest.push_back(key);
    }*/

    //from previous milestone
    //CityLookup(int choice) {
    //    chosenCache = choice;
    //    if (chosenCache == 1) {
    //        fifoCache = new FIFOCache();
    //    }
    //    else if(chosenCache == 2){
    //        lfuCache = new LFUCache();
    //    }
    //    else if (chosenCache == 3) {
    //        randomReplacementCache = new RandomReplacementCache();
    //    }

    //}

    CityLookup(int choice, Trie* trieInstance) {
        chosenCache = choice;
        trie = trieInstance;

        if (chosenCache == 1) {
            fifoCache = new FIFOCache();
        }
        else if (chosenCache == 2) {
            lfuCache = new LFUCache();
        }
        else if (chosenCache == 3) {
            randomReplacementCache = new RandomReplacementCache();
        }

    }

    int searchCache(const string& fileName, const string& country, const string& city) {

        string s = country + "," + city;
        int cached = -1;

        if (chosenCache == 1) {
            cached = fifoCache->searchCache(s);
        }
        else if (chosenCache ==2) {
            cached = lfuCache->searchCache(s);
        }
        else if (chosenCache == 3) {
            cached = randomReplacementCache->searchCache(s);
        }


        if (cached != -1) {
            cout << "Cache: " << s << " population: " << cached << endl;
            return cached;
        }

        CityStruct cityStruct = CSVReader::searchCity(fileName, country, city);

        if (cityStruct.population > -1) {
            if (chosenCache == 1) {
                fifoCache->updateCache(s, cityStruct.population);
            }
            else if (chosenCache == 2) {
                lfuCache->updateCache(s, cityStruct.population);
            }
            else if (chosenCache == 3) {
                randomReplacementCache->updateCache(s, cityStruct.population);
            }

            return cityStruct.population;
       
        }

        return -1; //if not found
    }
};