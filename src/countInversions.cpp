#include "interviewkit.hpp"

long mergeSort(vector<int> &, int, int);
long merge(vector<int> &, int, int, int);

// Complete the countInversions function below.
long countInversions(vector<int> arr)
{
    long ans = 0;
    ans = mergeSort(arr, 0, arr.size() - 1);
    return ans;
}

long merge(vector<int> &arr, int left_i, int mid_i, int right_i)
{
    long ans = 0;
    int i, j, k;

    vector<int> left_arr(&arr[left_i], &arr[mid_i + 1]);
    vector<int> right_arr(&arr[mid_i + 1], &arr[right_i + 1]);

    i = j = 0;
    k = left_i;
    while (i < left_arr.size() && j < right_arr.size())
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            ans += left_arr.size() - i;
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_arr.size())
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_arr.size())
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
    return ans;
}

long mergeSort(vector<int> &arr, int left_i, int right_i)
{
    long ans = 0;
    if (left_i < right_i)
    {
        int mid_i = left_i + (right_i - left_i) / 2;

        ans += mergeSort(arr, left_i, mid_i);
        ans += mergeSort(arr, mid_i + 1, right_i);

        ans += merge(arr, left_i, mid_i, right_i);
    }
    return ans;
}

int main()
{
    vector<int> expenditure = {2, 1, 3, 1, 2};
    // vector<int> expenditure = {1, 1, 1, 2, 2};
    // vector<int> expenditure = {38, 27, 43, 3, 9, 82, 10};
    auto result = countInversions(expenditure);
    cout << "Result: " << result << "\n";
    return 0;
}
