#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> s;

    int num;
    while(n--){
        cin >> num;
        s.insert(num);
    }

    cout << s.size();

    return 0;
}