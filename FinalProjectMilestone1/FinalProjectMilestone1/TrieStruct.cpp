#include <string>
#include <unordered_map>


using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> elements;
    unordered_map<string, int> country_pop;
    bool isEndOfCity = false;
};
