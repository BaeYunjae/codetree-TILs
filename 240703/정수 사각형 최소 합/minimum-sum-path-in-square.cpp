#include <iostream>
using namespace std;

int N;
int map[101][101];

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }

    int d[101][101] = {0};
    d[1][N] = map[1][N];

    // 초기화
    for (int i = 2; i <= N; i++){
        d[i][N] = d[i - 1][N] + map[i][N];
    } 

    for (int i = N - 1; i >= 1; i--){
        d[1][i] = d[1][i + 1] + map[1][i];
    }

    for (int i = 2; i <= N; i++){
        for (int j = N - 1; j >= 1; j--){
            d[i][j] = min(d[i - 1][j] + map[i][j], d[i][j + 1] + map[i][j]);
        }
    }

    cout << d[N][1];

    return 0;
}