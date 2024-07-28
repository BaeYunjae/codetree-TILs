#include <iostream>
using namespace std;

int n, m;
long long arr[100001];

int binarySearch(int target){
    int left = 0, right = n - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] == target) return mid + 1;

        if (arr[mid] > target){
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++){
        int num;
        cin >> num;

        cout << binarySearch(num) << "\n";
    }
    
    return 0;
}