#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    unordered_map<char, int> um;
    for (int i = 0; i < str.length(); i++){
        um[str[i]]++;
    }

    for (auto iter : um){
        if (iter.second > 1) continue;
        cout << iter.first;
        return 0;
    }
    cout << "None";
}