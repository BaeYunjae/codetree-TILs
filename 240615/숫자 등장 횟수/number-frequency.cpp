#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> um;

    int n, m;
    cin >> n >> m;

    int x;
    while(n--){
        cin >> x;
        um[x]++;
    }

    int q;
    while(m--){
        cin >> q;
        cout << um[q] << " ";
    }


    return 0;
}