#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    int a[200001], b[200001];

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    int ans = n + m;
    unordered_set<int> s;

    for (int i = 0; i < n; i++){
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++){
        if (s.find(b[i]) != s.end()) ans -= 2;
    }

    cout << ans;

    return 0;
}