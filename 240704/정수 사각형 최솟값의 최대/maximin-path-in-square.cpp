#include <iostream>
#include <algorithm>
using namespace std;

int n;
int map[101][101];
int d[101][101];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    d[1][1] = map[1][1];

    for (int i = 2; i <= n; i++){
        d[1][i] = min(d[1][i - 1], map[1][i]);
    }

    for (int i = 2; i <= n; i++){
        d[i][1] = min(d[i - 1][1], map[i][1]);
    }

    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= n; j++){
            // 1. map[i][j]가 가장 작으면 확정
            // 2. 위쪽과 왼쪽 중 map보다 작은 값인데, 둘 중에 큰 값
            d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            if (d[i][j] > map[i][j]) d[i][j] = map[i][j];
        }
    }

    cout << d[n][n];



    return 0;
}