#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX 100001

int n, k;
int a[MAX], b[MAX];
int arr[MAX];
int ans[MAX];
unordered_set<int> s[MAX];

int main(){
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        cin >> a[i] >> b[i];
    }

    // 초기값 
    for (int i = 1; i <= n; i++){
        arr[i] = i;
        s[i].insert(i);
        ans[i] = 1;
    }

    for (int cnt = 0; cnt < 3; cnt++){
        for (int i = 0; i < k; i++){
            swap(arr[a[i]], arr[b[i]]);

            if (s[arr[a[i]]].find(a[i]) == s[arr[a[i]]].end()){
                s[arr[a[i]]].insert(a[i]);
                ans[arr[a[i]]]++;
            }

            if (s[arr[b[i]]].find(b[i]) == s[arr[b[i]]].end()){
                s[arr[b[i]]].insert(b[i]);
                ans[arr[b[i]]]++;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}