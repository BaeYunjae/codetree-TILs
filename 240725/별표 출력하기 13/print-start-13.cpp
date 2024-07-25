#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a = n, b = 1;
    for (int i = 0; i < n * 2; i++){
        if (i % 2 == 0){
            for (int j = 0; j < a; j++){
                cout << "* ";
            }
            a--;
        }
        else{
            for (int j = 0; j < b; j++){
                cout << "* ";
            }
            b++;
        }
        cout << "\n";
    }

    return 0;
}