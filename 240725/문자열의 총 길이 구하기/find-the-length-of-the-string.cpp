#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string str;

    for (int i = 0; i < 10; i++){
        cin >> str;
        cnt += str.length();
    }

    cout << cnt;

    return 0;
}