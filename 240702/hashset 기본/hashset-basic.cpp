#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> s;

    string cmd;
    int x;

    while(n--){
        cin >> cmd >> x;

        if (cmd == "add"){
                s.insert(x);
        }
        else if(cmd == "remove"){
                s.erase(x);
        }
        else if (cmd == "find"){
            if (s.find(x) != s.end()){
                cout << "true\n";
            }
            else{
                cout << "false\n";
            }
        }
    }

    return 0;
}