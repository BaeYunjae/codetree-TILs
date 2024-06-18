#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    unordered_map<int, int> um;
    int ans = 0;

    while(n--){
        int x;
        cin >> x;
        um[x]++;
    }

    for (auto it = um.begin(); it != um.end(); it++){
        int num = it->first;
        int diff = k - num;

        if (num == diff){
            ans += (it->second * (it->second - 1));
        }
        else{
            ans += it->second * um[diff];
        }
    }

    cout << ans / 2;

    return 0;
}