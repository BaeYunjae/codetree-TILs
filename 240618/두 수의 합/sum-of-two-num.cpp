#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[100000];
unordered_map<long long, int> cnt;

int main(){
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        long long diff = (long long)k - arr[i];
        ans += cnt[diff];

        cnt[arr[i]]++;
    }

    cout << ans;
    return 0;
}