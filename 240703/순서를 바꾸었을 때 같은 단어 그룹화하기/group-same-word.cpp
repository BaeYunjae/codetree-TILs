#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> um;

    while(n--){
        string word;
        cin >> word;

        sort(word.begin(), word.end());
        um[word]++;
    }

    int ans = 0;

    for (auto iter : um){
        if (iter.second > ans){
            ans = iter.second;
        }
    }

    cout << ans;
    
    return 0;
}