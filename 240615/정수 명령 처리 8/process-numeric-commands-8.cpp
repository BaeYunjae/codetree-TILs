#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> ls;
    string cmd;
    int a; 

    while(n--){
        cin >> cmd;

        if (cmd == "push_front"){
            cin >> a;
            ls.push_front(a);
        } 
        else if (cmd == "push_back"){
            cin >> a;
            ls.push_back(a);
        }
        else if (cmd == "pop_front"){
            if (!ls.empty()){
                cout << ls.front() << "\n";
                ls.pop_front();
            }
        }
        else if (cmd == "pop_back"){
            if (!ls.empty()){
                cout << ls.back() << "\n";
                ls.pop_back();
            }
        }
        else if (cmd == "size"){
            cout << ls.size() << "\n";
        }
        else if (cmd == "empty"){
            if (ls.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (cmd == "front"){
            cout << ls.front() << "\n";
        }
        else if (cmd == "back"){
            cout << ls.back() << "\n";
        }
    }

    return 0;
}