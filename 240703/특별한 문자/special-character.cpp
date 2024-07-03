#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    cin >> str;

    unordered_map<char, int> um;
    for (int i = 0; i < str.length(); i++){
        um[str[i]]++;
    }

    vector<pair<char, int>> vect(um.begin(), um.end());

    for (auto iter = vect.rbegin(); iter != vect.rend(); iter++){
        if (iter->second > 1) continue;
        cout << iter -> first;
        return 0;
    }

    cout << "None";
}