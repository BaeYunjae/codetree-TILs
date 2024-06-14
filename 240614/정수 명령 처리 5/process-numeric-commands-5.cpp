#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    string cmd;
    int x;

    while(n--){
        cin >> cmd;

        if (cmd == "push_back"){
            cin >> x;
            v.push_back(x);
        }
        else if (cmd == "pop_back"){
            v.pop_back();
        }
        else if (cmd == "size"){
            cout << v.size() << "\n";
        }
        else if (cmd == "get"){
            cin >> x;
            cout << v[x - 1] << "\n";
        }
    }


    return 0;
}