#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<char, pair<int, int>> a, pair<char, pair<int, int>> b){
    if (a.second.second == b.second.second){
        return a.second.first < b.second.first;
    }
    return a.second.second < b.second.second;
}

int main() {
    string str;
    cin >> str;

    int idx = 0;
    unordered_map<char, pair<int, int>> um;
    for (int i = 0; i < str.length(); i++){
        if (um.find(str[i]) == um.end()){
            um[str[i]].first = i;
        }
        um[str[i]].second++;
    }

    vector<pair<char, pair<int,int>>> vect(um.begin(), um.end());
    sort(vect.begin(), vect.end(), compare);

    for (auto iter = vect.begin(); iter != vect.end(); iter++){
        if (iter->second.second > 1) continue;
        cout << iter -> first;
        return 0;
    }


    cout << "None";
}