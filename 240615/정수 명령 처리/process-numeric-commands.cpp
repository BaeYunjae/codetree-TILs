#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;
    string cmd;

    while (n--){
        cin >> cmd;

        if (cmd == "push"){
            int a;
            cin >> a;
            st.push(a);
        }
        else if (cmd == "pop"){
            cout << st.top() << "\n";
            st.pop();
        }
        else if (cmd == "size"){
            cout << st.size() << "\n";
        }
        else if (cmd == "empty"){
            if (st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (cmd == "top"){
            cout << st.top() << "\n";
        }
    }
    return 0;
}