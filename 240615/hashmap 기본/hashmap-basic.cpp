#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string cmd;
    int k, v;

    unordered_map<int, int> um;

    while (n--){
        cin >> cmd >> k;

        if (cmd == "add"){
            cin >> v;
            um[k] = v;    
        }
        else if (cmd == "remove")
            um.erase(k);
        else if (cmd == "find"){
            if (um.find(k) != um.end())
                cout << um[k] << "\n";
            else
                cout << "None\n";
        }
    }
    
    return 0;
}