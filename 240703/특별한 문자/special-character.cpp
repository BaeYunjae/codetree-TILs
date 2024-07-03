#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (pair<int, int> one, pair<int, int> two) {
    return one.second < two.second;
}

int main() {
    string str;
    cin >> str;

    unordered_map<char, int> um;
    for (int i = 0; i < str.length(); i++){
        um[str[i]]++;
    }

    vector<pair<char, int>> sorted(um.begin(), um.end());
    sort(sorted.begin(), sorted.end(), compare);

    if (sorted[0].second == 1){
        cout << sorted[0].first;
    }
    else {
        cout << "None";
    }
}