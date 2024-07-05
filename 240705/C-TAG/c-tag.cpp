#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
string A[501], B[501];
unordered_set<string> us;

void input(){
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }
}

bool TestLocation(int x, int y, int z){
    us.clear();

    for (int i = 0; i < n; i++){
        us.insert(A[i].substr(x, 1) + A[i].substr(y, 1), A[i].substr(z, 1));
    }

    for (int i = 0; i < n; i++){
        if (us.find(B[i].substr(x, 1) + B[i].substr(y, 1) + B[i].substr(z, 1)) != us.end())
            return false;
    }

    return true;
}

int main() {
    cin >> n >> m;

    input();

    // 125,000,000

    // 1. A 중에서 3개의 조합 저장
    // 2. B에서 3개의 조합이 없으면 ans++

    int ans = 0;

    for (int i = 0; i < m - 2; i++){
        for (int j = i + 1; j < m - 1; j++){
            for (int k = j + 1; k < m; k++){
                if (TestLocation(i, j, k)) ans++;
            }
        }
    }
    
    cout << ans;

    return 0;
}