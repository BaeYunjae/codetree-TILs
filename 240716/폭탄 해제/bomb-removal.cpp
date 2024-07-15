#include <iostream>
#include <string>
using namespace std;

class Bomb{
    public:
        string code;
        char color;
        int sec;

        Bomb(string code = 0, char color = 0, int sec = 0){
            this->code = code;
            this->color = color;
            this->sec = sec;
        }
};

int main() {
    string a;
    char b;
    int c;

    cin >> a >> b >> c;

    Bomb input = Bomb(a, b, c);

    cout << "code : " << input.code << "\n" << "color : " << input.color << "\n" << "second : " << input.sec << "\n";

    

    return 0;
}