#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    set<pair<int, int> > s;

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        pair<int, int> ans;
        if (s.lower_bound(make_pair(x, y)) == s.end()){
            ans = make_pair(-1, -1);
        }
        else{
            ans = *s.lower_bound(make_pair(x, y));
        }
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}