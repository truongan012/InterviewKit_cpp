#include "interviewkit.hpp"

// Complete the commonChild function below.
int commonChild(string s1, string s2)
{
    s1 = " " + s1;
    s2 = " " + s2;
    vector<vector<size_t>> lcs(s2.size(), vector<size_t>(s2.size(), 0));
    for (size_t i = 1; i < s1.size(); i++)
    {
        for (size_t j = 1; j < s2.size(); j++)
        {
            lcs[i][j] = s1[i] == s2[j] ? lcs[i - 1][j - 1] + 1 : max(lcs[i][j - 1], lcs[i - 1][j]);
        }
    }
    return lcs[s1.size() - 1][s2.size() - 1];
}

int main()
{
    string s1 = "SHINCHAN";
    string s2 = "NOHARAAA";
    int result = commonChild(s1, s2);
    cout << result << "\n";
    return 0;
}
