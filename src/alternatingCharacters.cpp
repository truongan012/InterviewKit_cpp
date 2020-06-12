#include "interviewkit.hpp"

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == s[i + 1])
        {
            count += 1;
        }
    }
    return count;
}

int main()
{
    string s = "ABBBBABBAA";
    int result = alternatingCharacters(s);
    cout << result << "\n";
    return 0;
}
