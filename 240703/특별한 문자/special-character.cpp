#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;
string str;

int main() {
    cin >> str;

    for (int i = 0; i < str.length(); i++){
        um[str[i]]++;
    }

    for (int i = 0; i < str.length(); i++){
        if (um[str[i]] == 1) {
            cout << str[i];
            return 0;
        }
    }

    cout << "None";
    
    return 0;
}