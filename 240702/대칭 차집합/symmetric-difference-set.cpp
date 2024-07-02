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

    unordered_set<int> s1;
    unordered_set<int> s2;

    for (int i = 0; i < n; i++){
        s1.insert(a[i]);
    }

    for (int i = 0; i < m; i++){
        s2.insert(b[i]);
    }

    unordered_set<int> ans_s;

    for (int i = 0; i < n; i++){
        if (s2.find(a[i]) == s2.end()) ans_s.insert(a[i]);
    }

    for (int i = 0; i < m; i++){
        if (s1.find(b[i]) == s1.end()) ans_s.insert(b[i]);
    } 


    cout << ans_s.size();

    return 0;
}