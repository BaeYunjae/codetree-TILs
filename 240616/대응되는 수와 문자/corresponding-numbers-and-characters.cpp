#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, string> um;

    for (int i = 1; i <= n; i++){
        string str;
        cin >> str;
        um[to_string(i)] = str;
        um[str] = to_string(i);
    }   

    while(m--){
        string target;
        cin >> target;
        cout << um[target] << "\n";
    }

    return 0;
}