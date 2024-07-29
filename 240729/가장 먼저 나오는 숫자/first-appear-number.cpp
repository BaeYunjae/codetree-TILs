#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];

int upperBound(int target){
    int left = 0;
    int right = n - 1;
    int res = 1e9;

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

    if (res == 1e9 || arr[res] != target) return -1;

    return res + 1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << upperBound(x) << "\n";
    }
    
    return 0;
}