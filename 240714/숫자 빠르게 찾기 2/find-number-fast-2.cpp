#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        s.insert(num);
    }

    while(m--){
        cin >> num;
        if (s.lower_bound(num) != s.end()){
            cout << *s.lower_bound(num) << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}