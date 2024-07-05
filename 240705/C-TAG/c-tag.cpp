#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int n, m;
string A[51], B[51];
unordered_set<string> us;

void input(){
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        cin >> B[i];
    }
}

int main() {
    cin >> n >> m;

    input();

    // 125,000,000

    // 1. A 중에서 3개의 조합 저장
    // 2. B에서 3개의 조합이 없으면 ans++

    int ans = 0;

    char word[4];
    for (int i = 0; i < m - 2; i++){
        for (int j = i + 1; j < m - 1; j++){
            for (int k = j + 1; k < m; k++){
                for (int l = 0; l < n; l++){
                    word[0] = A[l][i];
                    word[1] = A[l][j];
                    word[2] = A[l][k];

                    string str(word);
                    
                    us.insert(word);
                }

                bool flag = false;

                for (int r = 0; r < n; r++){
                    word[0] = B[r][i];
                    word[1] = B[r][j];
                    word[2] = B[r][k];

                    string str(word);

                    if (us.find(word) != us.end()) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) ans++;
                us.clear();
            }
        }
    }
    
    cout << ans;


    return 0;
}