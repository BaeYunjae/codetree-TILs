#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    int n, m;
    cin >> n >> m;

    for (int i = m; i >= 1; i--){
        s.insert(i);
    }

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        s.erase(x);
        
        cout << *s.rbegin() << "\n";
    }

    return 0;
}