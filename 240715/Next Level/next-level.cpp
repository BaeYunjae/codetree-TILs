#include <iostream>
#include <string>
using namespace std;

class User{
    public:
        string id;
        int level;

        User(string id = "codetree", int level = 10){
            this->id = id;
            this->level = level;
        }
};

int main() {

    User user1 = User();

    cout << "user " << user1.id << " lv " << user1.level << "\n";
    
    string new_id;
    int new_lv;

    cin >> new_id >> new_lv;
    
    user1.id = new_id;
    user1.level = new_lv;

    cout << "user " << user1.id << " lv " << user1.level << "\n";

    return 0;
}