#include "interviewkit.hpp"

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr)
{
    sort(arr.begin(),arr.end());
    int unfairness = arr[arr.size() - 1] - arr[0];
    for (size_t i = 0; i < arr.size() - k + 1; i++)
    {
        int min = arr[i];
        int max = arr[i + k - 1];
        if (max - min < unfairness) {
            unfairness = max - min;
        }
    }
    return unfairness;
}

int main()
{
    int k = 3;
    vector<int> arr = {100, 200, 300, 350, 400, 401, 402};
    int result = maxMin(k, arr);
    cout << result << "\n";
    return 0;
}