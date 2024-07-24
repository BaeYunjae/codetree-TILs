#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;
    s.insert(0);
    
    while(n--){
        int num;
        cin >> num;
        s.insert(num);

        int minDist = 1e9;

        int a, b;
        set<int>::iterator it;
        for (auto i = s.begin(); i != s.end(); i++){
            if (*i == *s.rbegin()) break;
            
            it = s.upper_bound(*i);
            a = *it;

            it--;
            b = *it;

            if (a - b >= minDist) break;
            
            minDist = min(minDist, a - b);
        }

        cout << minDist << "\n";
    }
    


    return 0;
}