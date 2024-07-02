#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    int arr[100001];
    int arr2[100001];

    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++){
        cin >> arr2[i];
    }


    unordered_set<int> s;
    for (int i = 0; i < n; i++){
        s.insert(arr[i]);
    }

    for (int i = 0; i < m; i++){
        if (s.find(arr2[i]) == s.end()){
            cout << 0 << " ";
        }
        else {
            cout << 1 << " ";
        }
    }

    return 0;
}