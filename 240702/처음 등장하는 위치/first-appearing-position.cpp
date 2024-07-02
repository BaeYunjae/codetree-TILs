#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> m;

    int num;
    for (int i = 1; i <= n; i++){
        cin >> num;
        if (m.find(num) != m.end()) continue;

        m[num] = i;
    }

    for (auto it = m.begin(); it != m.end(); it++){
        cout << it -> first << " " << it -> second << "\n";
    }

    return 0;
}