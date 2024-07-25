#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    int cnt = 0;
    int a = 0;

    for (int i = 0; i < n; i++){
        cin >> str;
        cnt += str.length();
        if (str[0] == 'a') a++;
    }

    cout << cnt << " " << a;

    return 0;
}