#include <iostream>
#include <string>
using namespace std;

class Data{
    public:
        string date, day, weather;

        Data(string date = "", string day = "", string weather = ""){
            this->date = date;
            this->day = day;
            this->weather = weather;
        }
};

int main() {
    int n;
    cin >> n;

    Data future[101];
    string near_rain = "2100-12-31";
    int ans_idx = 0;

    string a, b, c;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c;
        future[i] = Data(a, b, c);

        if (c == "Rain" && near_rain > a){
            near_rain = a;
            ans_idx = i;
        }
    }

    cout << future[ans_idx].date << " " << future[ans_idx].day << " " << future[ans_idx].weather;

    return 0;
}