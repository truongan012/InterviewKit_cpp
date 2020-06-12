#include "interviewkit.hpp"

// Complete the substrCount function below.
long substrCount(int n, string s)
{
    long ans = 0;
    vector<tuple<char, long>> lst;
    long cnt = 1;
    auto c = s[0];

    for (int i = 1; i <= n; i++)
    {
        if (s[i] != c)
        {
            lst.push_back(make_tuple(c, cnt));
            cnt = 1;
            c = s[i];
        }
        else
        {
            cnt++;
        }
    }

    for (auto ele : lst)
    {
        ans += get<1>(ele) * (get<1>(ele) + 1) / 2;
    }

    for (int i = 1; i < lst.size() - 1; i++)
    {
        if (get<0>(lst[i - 1]) == get<0>(lst[i + 1]) && get<1>(lst[i]) == 1)
            ans += min(get<1>(lst[i - 1]), get<1>(lst[i + 1]));
    }

    return ans;
}

int main()
{
    string s = "abcbaba";
    int n = s.length();
    long result = substrCount(n, s);
    cout << result << "\n";
    return 0;
}
