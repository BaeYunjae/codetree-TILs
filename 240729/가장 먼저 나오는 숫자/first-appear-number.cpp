#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];

int lowerBound(int target){
    int left = 0;
    int right = n;
    int res = n + 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] >= target){
            right = mid - 1;
            res = min(res, mid);
        }
        else {
            left = mid + 1;
        }
    }

    return res;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        
        int now = lowerBound(x);
        if (now <= n && arr[now] == x){
            cout << now << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}