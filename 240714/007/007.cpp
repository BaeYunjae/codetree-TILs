#include <iostream>
#include <string>
using namespace std;

class Secret{
    public:
        string code;
        char place;
        int time;

        Secret(string code, char place, int time){
            this->code = code;
            this->place = place;
            this->time = time;
        }
};

int main() {
    string c;
    char p;
    int t;

    cin >> c >> p >> t;

    Secret input = Secret(c, p, t);

    cout << "secret code : " << input.code << "\n";
    cout << "meeting point : " << input.place << "\n";
    cout << "time : " << input.time;

    return 0;
}