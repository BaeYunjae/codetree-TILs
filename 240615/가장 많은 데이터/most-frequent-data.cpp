#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> um;

    string str;
    int ans = 0;

    while(n--){
        cin >> str;
        um[str]++;
        if (um[str] > ans)
            ans = um[str];
    }

    cout << ans;

    return 0;
}