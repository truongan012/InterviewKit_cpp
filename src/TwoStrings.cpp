#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2)
{
    string result = "";
    set<char> set1(begin(s1), end(s1));
    set<char> set2(begin(s2), end(s2));
    set<char> intersec;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersec, intersec.begin()));
    if (intersec.empty()) result = "NO";
    else result = "YES";
    return result;
}

int main()
{
    int q = 1;

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s1 = "hello";

        string s2 = "world";

        string result = twoStrings(s1, s2);
        
        printf("%s", result);
    }
    return 0;
}
