#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;

    vector<string> vect;
    for (int i = 0; i < 4; i++){
        cin >> str;
        vect.push_back(str);
    }

    for (int i = 3; i >= 0; i--){
        cout << vect[i] << "\n";
    }

    return 0;
}