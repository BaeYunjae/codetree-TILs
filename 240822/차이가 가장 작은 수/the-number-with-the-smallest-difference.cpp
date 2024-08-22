#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
set<int> s;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;

        s.insert(num);
    }

    int ans = 1e9 + 1;
    for (auto now : s){
        set<int>::iterator it = s.upper_bound(now);
        while(1){
            if (it == s.end()) break;
            if (*it - (int)now >= m){
                ans = min(ans, *it - (int)now);
                break;
            }
            else{
                it++;
            }
        }
    }

    if (ans == 1e9 + 1) cout << -1;
    else cout << ans;

    return 0;
}