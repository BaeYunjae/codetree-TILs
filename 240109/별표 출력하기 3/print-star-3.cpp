#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";               // 공백 2개
        }
        for (int j = 0; j < (2 * n) - (2 * i) - 1; j++) {
            cout << "* ";
        }
        cout << '\n';
    }


    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 2 * i ; j++) {
    //         cout << " ";
    //     }
    //     for (int j = 2 * i; j < 2 * (n - 1) + 1; j++) {  // n = 5 / i = 0, 1, 2, 3, 4 / * : 9, 7, 5, 3, 1 
    //         cout << "* "; 
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}