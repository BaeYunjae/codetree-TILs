#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    int a[100001], b[100001];

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    unordered_set<int> s;

    for (int i = 0; i < n; i++){
        s.insert(a[i]);    
    }

    for (int i = 0; i < m; i++){
        if (s.find(b[i]) == s.end()){
            cout << 0 << "\n";
        }
        else {
            cout << 1 << "\n";
        }
    }

    return 0;
}