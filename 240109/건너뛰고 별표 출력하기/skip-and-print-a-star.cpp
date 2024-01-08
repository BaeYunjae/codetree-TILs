#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n\n";
    }

    // for (int i = 1; i < n; i++) {
    //     for (int j = n - 1; j >= i; j--) {
    //         cout << "*";
    //     }
    //     cout << "\n\n";
    // }

    // 길이가 n - 1인 직각삼각형을 뒤집는다.
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << "\n\n";
    }


    return 0;
}