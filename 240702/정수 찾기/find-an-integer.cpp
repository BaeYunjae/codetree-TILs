#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    unordered_set<int> s;

    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }

    cin >> m;

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;

        cout << (int)(s.find(x) != s.end()) << "\n";
    }

    return 0;
}