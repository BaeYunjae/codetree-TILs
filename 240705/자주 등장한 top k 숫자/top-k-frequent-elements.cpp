#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

int n, k;
unordered_map<int, int> um;

int main() {
    cin >> n >> k;

    int num;
    while (n--){
        cin >> num;
        um[num]++;
    }
    
    vector<pair<int, int>> vect(um.begin(), um.end());
    sort(vect.begin(), vect.end(), compare);

    for (int i = 0; i < k; i++){
        cout << vect[i].first << " ";
    }

    return 0;
}