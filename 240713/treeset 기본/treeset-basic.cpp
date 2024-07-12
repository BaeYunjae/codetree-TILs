#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> treeset;

    int x;
    while(n--){
        string cmd;
        cin >> cmd;
        if (cmd == "add"){
            cin >> x;
            treeset.insert(x);
        }
        else if (cmd == "remove"){
            cin >> x;
            treeset.erase(x);
        }
        else if (cmd == "find"){
            cin >> x;
            if (treeset.find(x) != treeset.end()){
                cout << "true\n";
            }
            else{
                cout << "false\n";
            }
        }
        else if (cmd == "lower_bound"){
            cin >> x;
            if (treeset.lower_bound(x) == treeset.end()){
                cout << "None\n";
            }
            else{
                cout << *treeset.lower_bound(x) << "\n";
            }
        }
        else if (cmd == "upper_bound"){
            cin >> x;
            if (treeset.upper_bound(x) == treeset.end()){
                cout << "None\n";
            }
            else{
                cout << *treeset.upper_bound(x) << "\n";
            }
        }
        else if (cmd == "largest"){
            if (treeset.rbegin() == treeset.rend()){
                cout << "None\n";
            }
            else {
                cout << *treeset.rbegin() << "\n";
            }
        }
        else if (cmd == "smallest"){
            if (treeset.rbegin() == treeset.rend()){
                cout << "None\n";
            }
            else{
                cout << *treeset.begin() << "\n";
            }
        }
    }


    return 0;
}