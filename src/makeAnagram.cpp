#include "interviewkit.hpp"

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    auto count = 0;
    vector<int> freq(26, 0);
    for (auto c : a) { ++freq[c - 'a']; }
    for (auto c : b) { --freq[c - 'a']; }
    for (auto val : freq) { count += abs(val); }
    return count;
}

int main()
{
    string a = "abcd";
    string b = "cde";
    int res = makeAnagram(a, b);
    cout << res << "\n";
    return 0;
}
