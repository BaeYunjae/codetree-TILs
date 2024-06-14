#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;
    string cmd;

    while(n--){
        cin >> cmd;
        
        if (cmd == "push"){
            int a;
            cin >> a;
            q.push(a);
        }
        else if (cmd == "pop"){
            if (!q.empty()) {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (cmd == "size"){
            cout << q.size() << "\n";
        }
        else if (cmd == "empty"){
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (cmd == "front"){
            cout << q.front() << "\n";
        }
    }
    return 0;
}