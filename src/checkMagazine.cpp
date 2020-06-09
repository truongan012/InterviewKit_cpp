#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<string> split_string(string);

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note)
{
    map<string, int> magazine_cnt, note_cnt;
    for (auto word : magazine)
        magazine_cnt[word] += 1;
    for (auto word : note)
        note_cnt[word] += 1;
    for (auto key : note_cnt)
    {
        if (magazine_cnt[key.first] == 0 || note_cnt[key.first] > magazine_cnt[key.first])
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    return;
}

int main()
{
    string magazine_tmp = "give me one grand today night";
    string note_tmp = "give one grand today";
    auto magazine = split_string(magazine_tmp);
    auto note = split_string(note_tmp);

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}