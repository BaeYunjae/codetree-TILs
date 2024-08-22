#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int nums[100001];
set<int> s;

int ans = 1e9 + 1;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
        s.insert(nums[i]);
    }

    for (int i = 0; i < n; i++){
        int x = nums[i];
        
        // x보다 m 이상 더 크면서 가장 작은 값
        // r - x >= m 만족하는 최소 r
        // r >= m + x 만족하는 최소 r
        if (s.lower_bound(m + x) != s.end()){
            ans = min(ans, *s.lower_bound(m + x) - x);
        }

        // x보다 m 이상 더 작으면서 가장 큰 값
        // x - r >= m
        // r <= x - m
        set<int>::iterator it = s.upper_bound(x - m);
        if (it != s.begin()){
            it--;
            ans = min(ans, x - *it);
        }

    }
    
    if (ans == 1e9 + 1) ans = -1;
    cout << ans;


    return 0;
}