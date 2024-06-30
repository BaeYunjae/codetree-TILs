#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    map<int, int> m;

    string cmd;
    int k, v;
    while(n--){
        cin >> cmd;
        if (cmd == "add"){
            cin >> k >> v;
            m[k] = v;
        }
        else if (cmd == "remove"){
            cin >> k;
            m.erase(k);
        }
        else if (cmd == "find"){
            cin >> k;
            if (m.find(k) != m.end()){
                cout << m[k] << "\n";
            }
            else{
                cout << "None\n";
            }
        }
        else if (cmd == "print_list"){
            if (m.empty()) cout << "None\n";
            else {
                for (auto it : m){
                    cout << it.second << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}