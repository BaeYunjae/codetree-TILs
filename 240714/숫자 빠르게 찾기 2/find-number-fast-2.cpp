#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[100001];
    int input[100001];
    set<int> s;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++){
        cin >> input[i];
    }

    for (int i = 0; i < n; i++){
        s.insert(arr[i]);
    }

    for (int i = 0; i < m; i++){
        if (s.lower_bound(input[i]) == s.end()){
            cout << -1 << "\n";
        }
        else {
            cout << *s.lower_bound(input[i]) << "\n";
        }
    }

    /* 
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
    */
    
    return 0;
}