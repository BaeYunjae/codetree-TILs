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
            if (v.size() > 0) v.pop_back();
        }
        else if (cmd == "size"){
            cout << v.size() << "\n";
        }
        else if (cmd == "get"){
            if (v.size() >= k) cout << v[k - 1] << "\n";
        }
    }


    return 0;
}