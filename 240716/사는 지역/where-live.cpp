#include <iostream>
#include <string>
using namespace std;

class Info{
    public:
        string name, address, region;
        
        Info(string name = "", string address = "", string region = ""){
            this->name = name;
            this->address = address;
            this->region = region;
        }
};

int main() {
    int n;
    cin >> n;

    Info infos[11];

    string a, b, c;
    string ans_name = "";
    int ans_idx = 0;

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        infos[i] = Info(a, b, c);

        if (ans_name < a) {
            ans_name = a;
            ans_idx = i;
        }
    }

    cout << "name " << infos[ans_idx].name << "\n";
    cout << "addr " << infos[ans_idx].address << "\n";
    cout << "city " << infos[ans_idx].region << "\n";

    return 0;
}