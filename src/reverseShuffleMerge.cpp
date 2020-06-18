#include "interviewkit.hpp"

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    map<char, int> cnt_s1, cnt_s2;
    for (char ch : s) {
        if (cnt_s1.find(ch) == cnt_s1.end()) {
            cnt_s1[ch] = 0;
        }
        cnt_s1[ch]++;
    }
    for (auto pair : cnt_s1) {
        cnt_s2[pair.first] = pair.second / 2;
    }
    vector<char> res;
    for (int i = s.size() - 1; i >= 0; i--) {
        char now = s[i];
        if (cnt_s2[now] > 0) {
            while (!res.empty()) {
                char last = res[res.size() - 1];
                if (last > now) {
                    int required = cnt_s2[last] + 1;
                    if (cnt_s1[last] >= required) {
                        res.pop_back();
                        cnt_s2[last]++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            res.push_back(now);
            cnt_s2[now]--;
        }
        cnt_s1[now]--;
    }
    return string(res.begin(), res.end());
}

int main()
{
    string s = "abcdefgabcdefg";
    string result = reverseShuffleMerge(s);
    cout << result << "\n";
    return 0;
}

