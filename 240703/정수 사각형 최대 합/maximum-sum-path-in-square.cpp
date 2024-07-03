#include <iostream>
using namespace std;

int N;
int map[101][101];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    int d[101][101] = {0};

    d[0][0] = map[0][0];

    // 초기화
    for (int i = 1; i < N; i++){
        d[i][0] = d[i - 1][0] + map[i][0];
    }

    for (int i = 1; i < N; i++){
        d[0][i] = d[0][i - 1] + map[0][i];
    }

    // 최대 합
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            d[i][j] = max(d[i][j - 1] + map[i][j], d[i - 1][j] + map[i][j]);
        }
    }

    cout << d[N - 1][N - 1];

    return 0;
}