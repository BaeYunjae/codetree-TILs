#include <iostream>
#include <set>
#define MAX 100000
using namespace std;

int n, m;
int target[MAX];
set<int> seats;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> target[i];
    }

    for (int i = 1; i <= m; i++){
        seats.insert(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++){
        // ai보다 큰 최초의 위치를 먼저 찾는다.
        auto it = seats.upper_bound(target[i]);

        // 큰 최초의 위치를 찾았을 때 
        // 첫번째 위치면 이 ai가 앉을 수 있는 곳이 없다는 의미
        if (it != seats.begin()){
            it--;
            seats.erase(*it);

            ans++;
        }
        else {
            break;
        }
    }


    cout << ans;    
    
    return 0;
}