#include "interviewkit.hpp"

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests)
{
    int balance = 0;
    int cnt = 0;
    sort(contests.begin(), contests.end(), [](vector<int> &a, vector<int> &b) { return a[0] > b[0]; });
    for (auto it = contests.begin(); it != contests.end(); it++)
    {
        if ((*it)[1] == 0)
        {
            balance += (*it)[0];
        }
        else
        {
            if(cnt < k){
                balance += (*it)[0];
                cnt++;
            }
            else{
                balance -= (*it)[0];
            }
        }
    }
    return balance;
}

int main()
{
    int k = 3;
    vector<vector<int>> contests = {{5, 1}, {2, 1}, {1, 1}, {8, 1}, {10, 0}, {5, 0}};
    // cout << contests[0][1] << endl;
    int result = luckBalance(k, contests);
    cout << result << "\n";
    return 0;
}
