#include <iostream>
using namespace std;

class Agent{
    public:
        char codename;
        int score;

        Agent (char codename = 0, int score = 0){
            this->codename = codename;
            this->score = score;
        }
};

int main() {
    
    Agent agents[5];

    char c;
    int s;

    int minScore = 100;
    int ans = 0;

    for (int i = 0; i < 5; i++){
        cin >> c >> s;

        if (s < minScore){
            minScore = s;
            ans = i;
        }

        agents[i] = Agent(c, s);
    }

    cout << agents[ans].codename << " " << agents[ans].score;



    return 0;
}