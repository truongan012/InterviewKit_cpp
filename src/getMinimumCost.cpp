#include "interviewkit.hpp"

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c)
{
    int cost = 0;
    int person = 0;
    vector<int> purchased(k, 0);

    sort(c.begin(), c.end());
    for (auto rit = c.rbegin(); rit != c.rend(); rit++)
    {
        cost += (*rit) * (++purchased[person++]);
        person = person < k ? person : 0;
    }
    return cost;
}

int main()
{
    int k = 3;
    vector<int> c = {1, 3, 5, 7, 9};
    int minimumCost = getMinimumCost(k, c);
    cout << minimumCost << "\n";
    return 0;
}
