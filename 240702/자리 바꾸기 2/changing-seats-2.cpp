#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int arr[100001];
    unordered_set<int> s[100001];
    
    for (int i = 1; i <= n; i++){
        s[i].insert(i);
        arr[i] = i;
    }

    vector<pair<int, int>> v;

    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;

        v.push_back(make_pair(a, b));
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < k; j++){
            int a = v[j].first;
            int b = v[j].second;

            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;

            s[arr[a]].insert(a);
            s[arr[b]].insert(b);
        }
    }

    for (int i = 1; i <= n; i++){
        cout << s[i].size() << "\n";
    }

    return 0;
}