#include "interviewkit.hpp"

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr)
{
    vector<int> res(arr.size());
    sort(arr.begin(),arr.end());
    adjacent_difference(arr.begin(),arr.end(), res.begin());
    return *(min_element(res.begin() + 1, res.end()));
}

int main()
{
    vector<int> arr = {1, -3, 71, 68, 17};
    int result = minimumAbsoluteDifference(arr);
    cout << result << "\n";
    return 0;
}
