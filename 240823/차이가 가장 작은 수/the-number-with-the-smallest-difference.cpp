#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int nums[100001];
set<int> s;

int ans = 21e8;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        s.insert(num);
    }

    for (auto it : s){
        // 차이가 m 이상
        auto iter = s.lower_bound(it - m);

        if (iter != s.end() && it - *iter >= m) ans = min(ans, abs(it - *iter));

        iter = s.lower_bound(it + m);

        if (iter != s.end() && *iter - it >= m) ans = min(ans, abs(*iter - it));
    }

    if (ans == 21e8) ans = -1;
    cout << ans;


    return 0;
}