#include <iostream>
#include <set>
#include <tuple>
using namespace std;

int n, m;
pair<int, int> points[100000];
pair<int, int> queries[100000];

set<pair<int, int> > s;

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;

        queries[i] = make_pair(x, y);
    }

    for (int i = 0; i < n; i++){
        s.insert(points[i]);
    }

    for (int i = 0; i < m; i++) {
        if (s.lower_bound(queries[i]) == s.end()){
            cout << "-1 -1\n";
        }
        else{
            int x, y;
            tie(x, y) = *s.lower_bound(queries[i]);
            cout << x << " " << y << "\n";
        }
    }

    return 0;
}