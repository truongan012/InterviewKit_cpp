#include "interviewkit.hpp"

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{
    map<long, long> doublets_able, triplets_able;
    long count = 0;
    for (auto v : arr)
    {
        count += triplets_able[v];
        triplets_able[v * r] += doublets_able[v];
        doublets_able[v * r] += 1;
    }
    return count;
}

int main()
{
    long r = 3;
    vector<long> arr = {1, 3, 9, 9, 27, 81};
    long ans = countTriplets(arr, r);
    cout << ans << "\n";
    return 0;
}
