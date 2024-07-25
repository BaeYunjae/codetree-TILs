#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    char target;
    cin >> target;

    int cnt = 0;
    for (char c : str){
        if (c == target){
            cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}