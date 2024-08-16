#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<int> s;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    for (int i = 0; i < k; i++){
        cout << *s.rbegin() << " ";
        s.erase(*s.rbegin());
    }

    return 0;
}