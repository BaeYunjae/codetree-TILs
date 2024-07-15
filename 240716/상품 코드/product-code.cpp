#include <iostream>
#include <string>
using namespace std;

int main() {
    pair<string, int> item = {"codetree", 50};

    cout << "product " << item.second << " is " << item.first << "\n";
    
    string name;
    int code;

    cin >> name >> code;

    item.first = name;
    item.second = code;

    cout << "product " << item.second << " is " << item.first << "\n";

    return 0;
}