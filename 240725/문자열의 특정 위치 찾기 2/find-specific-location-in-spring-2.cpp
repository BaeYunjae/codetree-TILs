#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[5] = {"apple", "banana", "grape", "blueberry", "orange"};
    char ch;
    cin >> ch;

    int cnt = 0;
    for (int i = 0; i < 5; i++){
        if (arr[i][2] == ch || arr[i][3] == ch) {
            cout << arr[i] << "\n";
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}