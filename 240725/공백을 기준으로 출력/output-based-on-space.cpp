#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    for (char c : str1){
        if (c == ' ') continue;
        cout << c;
    }
    for (char c : str2){
        if (c == ' ') continue;
        cout << c;
    }

    return 0;
}