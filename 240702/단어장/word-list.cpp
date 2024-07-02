#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;

    while(n--){
        string str;
        cin >> str;
        m[str]++;        
    }

    for (auto it = m.begin(); it != m.end(); it++){
        cout << it -> first << " " << it->second << "\n";
    }

    return 0;
}