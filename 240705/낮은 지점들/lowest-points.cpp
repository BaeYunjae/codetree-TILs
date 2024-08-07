#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long long, long long> um;

int main() {
    cin >> n;

    int x, y;
    while(n--){
        cin >> x >> y;

        if (um.count(x) == 0) um[x] = y;
        else if (um[x] > y) um[x] = y;
    }

    long long ans = 0;
    for (auto iter : um){
        ans += iter.second;
    }

    cout << ans;
    
    return 0;
}