#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n;
int queries[100001];
set<int> s;

int ans = 21e8;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> queries[i];
    }

    // x = 0에 점을 놓고 시작
    s.insert(0);

    for (int i = 0; i < n; i++){
        // 가장 근처에 있는 오른쪽 점 찾기
        set<int>::iterator it = s.upper_bound(queries[i]);

        // 존재한다면, 거리 중 최솟값 갱신
        if (it != s.end()){
            ans = min(ans, *it - queries[i]);
        }

        // 가장 근처에 있는 왼쪽 점 찾기
        it--;
        ans = min(ans, queries[i] - *it);

        s.insert(queries[i]);
        cout << ans << "\n";
    }

    return 0;
}