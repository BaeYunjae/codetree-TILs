#include <iostream>
#include <string>
using namespace std;

int main() {
    string str[10];
    char ch;

    for (int i = 0; i < 10; i++){
        cin >> str[i];
    }

    cin >> ch;

    for (int i = 0; i < 10; i++){
        if (str[i][str[i].length() - 1] == ch) cout << str[i] << "\n";
    }

    return 0;
}