#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < (2 * n) - (2 * i) - 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < (2 * n) - (2 * i) - 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }



    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         cout << "  ";
    //     }
    //     for (int j = (2 * n) - (2 * i) - 1; j > 0; j--) {
    //         cout << "* ";
    //     }
    //     cout << endl; 
    // }

    // /*
    // i    j    공백
    // 0          n
    // 1        n - 2
    // 2        n - 4    
    // */


    // for (int i = 0; i < n - 1; i++) {                
    //     for (int j = 0; j < n - i - 2 ; j++) {                    
    //         cout << "  ";               
    //     }
    //     for (int j = 0; j < 2 * i + 3; j++) {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }


    return 0;
}