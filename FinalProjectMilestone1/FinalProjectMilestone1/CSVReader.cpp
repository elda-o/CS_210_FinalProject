#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "CityStruct.cpp"
#include "Trie.cpp"
using namespace std;

class CSVReader {
public:

    static void TrieData(const string& filename, Trie& trie){

        ifstream file(filename);
        string line, word;

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> row;
            while (getline(ss, word, ',')) {
                row.push_back(word);
            }
            if (row.size() < 3) {
                continue;
            }

            trie.insert(row[1], row[0], stoi(row[2]));
            cout << "Inserted: " << row[1] << "," << row[0] << "," << row[2] << endl;

        }
        file.close();

    }
    static vector<vector<string>> readCSV(const string& filename) {
        ifstream file(filename);
        vector<vector<string>> data;
        string line, word;

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return data;
        }

        while (getline(file, line)) {
            stringstream ss(line);
            vector<string> row;
            while (getline(ss, word, ',')) {
                row.push_back(word);
            }
            data.push_back(row);
        }
        file.close();
        return data;
    }

    static CityStruct searchCity(const string& fileName, const string& country, const string& city) {
        vector<vector<string>> data = readCSV(fileName);

        for (const auto& row : data) {
            if (row.size() < 3) continue;
            if (row[0] == country && row[1] == city) {
                return { row[0], row[1], stoi(row[2]) };
            }
        }

        cerr << "City not found" << endl;

        return { "", "", -1 };
    }
};
