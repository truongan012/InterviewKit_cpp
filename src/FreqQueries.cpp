#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries)
{
    vector<int> ans;
    map<int, int> freq, cnt;
    for (auto q : queries)
    {
        switch (q[0])
        {
        case 1:
            cnt[freq[q[1]]] -= 1;
            freq[q[1]] += 1;
            cnt[freq[q[1]]] += 1;
            break;
        case 2:
            if (freq[q[1]] > 0)
            {
                cnt[freq[q[1]]] -= 1;
                freq[q[1]] -= 1;
                cnt[freq[q[1]]] += 1;
            }
            break;
        default:
            ans.push_back(cnt[q[1]] > 0 ? 1 : 0);
            break;
        }
    }
    return ans;
}

int main()
{
    const vector<vector<int>> queries = {{1, 3},
                                         {2, 3},
                                         {3, 2},
                                         {1, 4},
                                         {1, 5},
                                         {1, 5},
                                         {1, 4},
                                         {3, 2},
                                         {2, 4},
                                         {3, 2}};

    vector<int> ans = freqQuery(queries);

    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}