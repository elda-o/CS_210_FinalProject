#include <iostream>
#include <vector>
#include "CityLookup.cpp"

using namespace std;

int main() {

    CityLookup cityLookup;

    string country;
    string city;
    string fileName = "world_cities.csv";

    while (true) {
        cout << "Enter a country code or exit to exit.";
        cin >> country;

        if (country == "exit") break;

        cout << "Enter a city name or exit to exit.";
        cin >> city;

        if (city == "exit") break;

        int population = cityLookup.searchCache(fileName, country, city);
        if (population > -1) {
            cout << "Population of " << city << ", " << country << " is: " << population << endl;
        }

    }

    return 0;
}