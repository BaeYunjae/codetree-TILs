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
        
        if (um.find(k - x) == um.end()){
            um[k - x] = 1;
        }
        else{
            for (int i = 0; i != um[k - x]; i++){
                ans++;
            }
            um[k - x]++;
        }
    }

    cout << ans;

    return 0;
}