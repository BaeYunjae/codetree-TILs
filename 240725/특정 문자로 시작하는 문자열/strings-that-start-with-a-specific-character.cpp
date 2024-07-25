#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int cnt = 0, lens = 0;
    string str[21];
    char ch;

    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }

    cin >> ch;

    for (int i = 0; i < n; i++){
        if (str[i][0] == ch) {
            cnt++;
            lens += str[i].length();
        }
    }

    cout << fixed;
    cout.precision(2);

    cout << cnt << " " << (double) lens / cnt;


    return 0;
}