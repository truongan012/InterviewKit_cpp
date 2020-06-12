#include "interviewkit.hpp"

// Complete the isValid function below.
string isValid(string s)
{
    map<char, int> counter;
    map<int, int> freq;
    for (auto c : s)
        counter[c] += 1;
    for (auto f : counter)
        freq[f.second] += 1;
    if (freq.size() == 1)
        return "YES";
    if (freq.size() == 2)
    {
        auto f1 = *freq.begin();
        auto f2 = *--freq.end();
        if ((f1.first == 1 && f1.second == 1) || (f2.first == 1 && f2.second == 1))
            return "YES";
        if (f1.second == 1 || f2.second == 1)
            if (abs(f1.first - f2.first) < 2)
                return "YES";
    }
    return "NO";
}

int main()
{
    string s = "ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd";
    string result = isValid(s);
    cout << result << "\n";
    return 0;
}
