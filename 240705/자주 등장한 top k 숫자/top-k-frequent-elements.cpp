#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
unordered_map<int, int> um;

int main() {
    cin >> n >> k;

    int num;
    while (n--){
        cin >> num;
        um[num]++;
    }

    vector<pair<int, int>> vect;

    for (auto iter : um){
        vect.push_back({iter.second, iter.first});
    }

    sort(vect.begin(), vect.end());

    for (int i = vect.size() - 1; i >= vect.size() - k; i--){
        cout << vect[i].second << " ";
    }

    return 0;
}