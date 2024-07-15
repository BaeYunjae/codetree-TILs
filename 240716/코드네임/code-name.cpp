#include <iostream>
#include <tuple>
using namespace std;

int main(){
    tuple<char, int> t[5];


    int minScore = 100;
    int ans = 0;

    for (int i = 0; i < 5; i++){
        char codename;
        int score;
        cin >> codename >> score;

        if (score < minScore){
            minScore = score;
            ans = i;
        }

        t[i] = make_tuple(codename, score);
    }

    char codename;
    int score;
    tie(codename, score) = t[ans];
    cout << codename << " " << score;

}