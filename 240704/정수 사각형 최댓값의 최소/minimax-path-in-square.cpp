#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int map[101][101];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int d[101][101];

    // 초기화
    for (int i = 1; i < n; i++){
        d[i][0] = max(d[i - 1][0], map[i][0]);
    }

    for (int i = 1; i < n; i++){
        d[0][i] = max(d[0][i - 1], map[0][i]);
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            d[i][j] = min(d[i - 1][j], d[i][j - 1]);
            if (d[i][j] < map[i][j]) d[i][j] = map[i][j];
        }
    }

    cout << d[n - 1][n - 1];

    return 0;
}