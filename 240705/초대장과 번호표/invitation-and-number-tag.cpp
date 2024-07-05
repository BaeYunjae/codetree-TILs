#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100000
#define MAX_G 250000

int N, G;
bool invited[MAX_N];
// 각 그룹마다 초대장을 받지 못한 사람들을 관리
unordered_set<int> groups[MAX_G];
// 각 사람의 소속 그룹, 연결리스트 
vector<int> people_groups[MAX_N];
queue<int> q;
int ans;

int main(){
    cin >> N >> G;

    for (int i = 0; i < G; i++){
        int s, x;
        cin >> s;
        for (int j = 0; j < s; j++){
            cin >> x;
            x--;
            groups[i].insert(x);
            people_groups[x].push_back(i);
        }
    }

    // 1번 사람은 무조건 초대
    q.push(0);
    invited[0] = true;

    while (!q.empty()){
        int now = q.front();
        q.pop();
        ans++;

        // 현재 번호 now가 들어있는 그룹에서 now 지운다.
        // hashset에는 그룹에서 초대받지 않은 인원만 남긴다.
        for (int i = 0; i < (int) people_groups[now].size(); i++){
            int g_num = people_groups[now][i];

            // 현재 번호 now는 초대받은 것이니까 지운다.
            groups[g_num].erase(now);
            // 초대받지 않은 인원이 1명이면 초대
            if ((int) groups[g_num].size() == 1){
                int p_num = *(groups[g_num].begin());
                if (!invited[p_num]){
                    invited[p_num] = true;
                    q.push(p_num);
                }
            }
        }
    }

    // 초대장을 받는 인원 출력 
    cout << ans;

    return 0;
}