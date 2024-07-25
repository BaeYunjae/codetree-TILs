#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 1, b = n;
    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            for (int j = 0; j < a; j++){
                cout << "* ";
            }
            a++;
        }
        else{
            for (int j = 0; j < b; j++){
                cout << "* ";
            }
            b--;
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++){
        if (i % 2 == 0){
            for (int j = 0; j < b; j++){
                cout << "* ";
            }
            b--;
        }
        else{
            for (int j = 0; j < a; j++){
                cout << "* ";
            }
            a++;
        }
        cout << "\n";
    }



    return 0;
}