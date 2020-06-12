#include "interviewkit.hpp"

using namespace std;

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k)
{
    sort(prices.begin(), prices.end());
    int total = 0, i = 0;
    while (i < prices.size() && total <= k)
    {
        total += prices[i];
        i++;
    }
    return i - 1;
}

int main()
{
    int k = 15;
    vector<int> prices = {3, 7, 2, 9, 4};
    int result = maximumToys(prices, k);
    cout << result << "\n";
    return 0;
}