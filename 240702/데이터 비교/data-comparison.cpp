#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    int arr[100001];

    cin >> n;

    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        arr[i] = num;
    }

    unordered_set<int> s;

    for (int i = 0; i < n; i++){
        s.insert(arr[i]);
    }

    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> num;
        if (s.find(num) == s.end()){
            cout << 0 << " ";
        }
        else {
            cout << 1 << " ";
        }
    }

    return 0;
}