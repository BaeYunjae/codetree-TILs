#include <iostream>
#include <set>
using namespace std;

int main() {
    int T, k, n;
    char cmd;
    cin >> T;

    while(T--){
        set<int> s;
        cin >> k;

        while(k--){
            cin >> cmd >> n;
            if (cmd == 'I'){
                s.insert(n);
            }
            else if (cmd == 'D' && (int) s.size() > 0){
                if (n == 1){
                    s.erase(*s.rbegin());
                }
                else {
                    s.erase(*s.begin());
                }
            }
        }

        if ((int) s.size() == 0) {
            cout << "EMPTY\n";
        }
        else{
            cout << *s.rbegin() << " " << *s.begin() << "\n";
        }
    }

    return 0;
}