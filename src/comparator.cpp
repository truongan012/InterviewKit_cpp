#include "interviewkit.hpp"
using namespace std;

struct Player
{
    int score;
    string name;
};

class Checker
{
public:
    // complete this method
    static int comparator(Player a, Player b)
    {
        if (a.score > b.score) return 1;
        else if (a.score < b.score) return -1;
        else if (a.name < b.name) return 1;
        else if (a.name > b.name) return -1;
        else return 0;
    }
};

bool compare(Player a, Player b)
{
    if (Checker::comparator(a, b) == -1)
        return false;
    return true;
}

int main()
{
    vector<Player> players;
    players.push_back({100, "amy"});
    players.push_back({100, "david"});
    players.push_back({50, "heraldo"});
    players.push_back({75, "aakansha"});
    players.push_back({150, "aleksa"});

    sort(players.begin(), players.end(), compare);

    for (int i = 0; i < players.size(); i++)
    {
        cout << players[i].name << " " << players[i].score << endl;
    }

    return 0;
}