#include <iostream>
using namespace std;

/*
  0 1 2 3 4    공백 별
0 v v *         2   1
1 v * * *       1   3
2 * * * * *     0   5
3 v * * *       1   3
4 v v *         2   1

*/

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
      for (int j = 0; j < n - (i + 1); j++){
        cout << " ";
      }
      for (int j = 0; j < (2 * i) + 1; j++){
        cout << "*";
      }
      cout << "\n";
    }

    for (int i = 0; i < n - 1; i++){
      for (int j = 0; j < i + 1; j++){
        cout << " ";
      }
      for (int j = 0; j < (2 * n) - (2 * i) - 3; j++){
        cout << "*";
      }
      cout << "\n";
    }
    
    return 0;
}