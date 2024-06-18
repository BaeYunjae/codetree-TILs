#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[1001];
unordered_map<int, int> freq;

int main(){
    cin >> n >> k;

    int ans = 0;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int i = 0; i < n; i++){
        freq[arr[i]]--;

        for (int j = 0; j < i; j++){
            if (freq.find(k - arr[i] - arr[j]) != freq.end()){
                ans += freq[k - arr[i] - arr[j]];
            }
        }
    }

    cout << ans;

    return 0;
}