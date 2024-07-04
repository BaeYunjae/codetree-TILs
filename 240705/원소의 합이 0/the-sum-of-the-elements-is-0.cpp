#include <iostream>
#include <unordered_map>
using namespace std;

int n;
int ans = 0;
int arr[4][5001];
unordered_map<int, int> um_one;
unordered_map<int, int> um_two;

int main() {
    cin >> n;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            um_one[arr[0][i] + arr[1][j]]++;
            um_two[arr[2][i] + arr[3][j]]++;
        }
    }

    for (auto it = um_one.begin(); it != um_one.end(); it++){
        int diff = -(it->first);
        if (um_two.find(diff) != um_two.end()){
            ans += um_two[diff]*(it->second);
        }
    }

    cout << ans;
    
    return 0;
}