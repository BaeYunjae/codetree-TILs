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


        if (um.find(x) == um.end()){
            um[x] = 1;
            if (um.find(k - x) == um.end()){
                um[k - x] = 1;
            }
            else{
                ans++;
            }
        }
        else{
            if (um.find(k - x) != um.end()){
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}