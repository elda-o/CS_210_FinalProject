#include <iostream>
#include <vector>
#include "CityLookup.cpp"

using namespace std;

int main() {

    string country;
    string city;
    string fileName = "world_cities.csv";
    int choice;

    while (true) {
        cout << "Enter a country code or exit to exit.";
        cin >> country;

        if (country == "exit") break;

        cout << "Enter a city name or exit to exit.";
        cin >> city;

        if (city == "exit") break;

        cout << "Choose which Cache method you want to use: " << endl;
        cout << "1. FIFO Cache " << endl;
        cout << "2. LFU Cache " << endl;
        cout << "3. Random Replacement Cache " << endl;

        cin >> choice;
        CityLookup cityLookup(choice);

        int population = cityLookup.searchCache(fileName, country, city);
        if (population > -1) {
            cout << "Population of " << city << ", " << country << " is: " << population << endl;
        }

    }

    return 0;
}