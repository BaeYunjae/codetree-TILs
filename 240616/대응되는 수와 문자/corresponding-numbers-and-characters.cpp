#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string words[100001];
    unordered_map<string, int> um;

    for (int i = 1; i <= n; i++){
        string str;
        cin >> str;
        words[i] = str;
        um[str] = i;
    }   

    while(m--){
        string key;
        cin >> key;
        
        if ('0' <= key[0] && key[0] <= '9') 
            cout << words[stoi(key)] << "\n";
        else    
            cout << um[key] << "\n";
    }

    return 0;
}