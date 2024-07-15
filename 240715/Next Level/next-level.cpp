#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main(){
    tuple<string, int> t = make_tuple("codetree", 10);

    string id;
    int level;
    tie(id, level) = t;

    cout << "user " << id << " lv " << level << "\n";

    cin >> id >> level;

    t = make_tuple(id, level);
    cout << "user " << id << " lv " << level << "\n";
}