#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <list>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s)
{
    map<string, int> char_cnt;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size() + 1; j++)
        {
            auto sub_s = s.substr(i, j - i);
            sort(sub_s.begin(), sub_s.end());
            char_cnt[sub_s] += 1;
        }
    }
    int ans = accumulate(char_cnt.begin(), char_cnt.end(), 0,
                         [](int prev, pair<string, int> item) { return prev + item.second * (item.second - 1) / 2; });
    return ans;
}

int main()
{
    string s = "abba";
    int result = sherlockAndAnagrams(s);
    cout << result << endl;
    return 0;
}
