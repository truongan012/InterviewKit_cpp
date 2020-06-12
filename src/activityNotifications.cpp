#include "interviewkit.hpp"

vector<double> medianSlidingWindow(vector<int> &, int);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d)
{
    int notif = 0;
    auto median = medianSlidingWindow(expenditure, d);
    for (int i = 0; i < expenditure.size() - d; i++)
    {
        if (expenditure[i + d] >= 2 * median[i])
            notif += 1;
    }
    return notif;
}

int main()
{
    int n = 9;
    int d = 4;
    vector<int> expenditure = {10, 20, 30, 40, 50, 60, 70, 80};
    int result = activityNotifications(expenditure, d);
    cout << result << "\n";
    return 0;
}

vector<double> medianSlidingWindow(vector<int> &nums, int k)
{
    multiset<int, less<int>> min_bst;
    // max_bst stores the smaller half seen so far.
    multiset<int, greater<int>> max_bst;
    vector<double> ans;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i >= k)
        {
            // Remove the element outside the window.
            if (max_bst.find(nums[i - k]) != max_bst.cend())
            {
                max_bst.erase(max_bst.find(nums[i - k]));
            }
            else
            {
                min_bst.erase(min_bst.find(nums[i - k]));
            }
        }

        // Balance smaller half and larger half.
        if (max_bst.empty() || nums[i] > *max_bst.cbegin())
        {
            min_bst.emplace(nums[i]);
            if (min_bst.size() > max_bst.size() + 1)
            {
                max_bst.emplace(*min_bst.cbegin());
                min_bst.erase(min_bst.cbegin());
            }
        }
        else
        {
            max_bst.emplace(nums[i]);
            if (max_bst.size() > min_bst.size())
            {
                min_bst.emplace(*max_bst.cbegin());
                max_bst.erase(max_bst.cbegin());
            }
        }

        // If window is full, get the median from 2 BST.
        if (i >= k - 1)
        {
            ans.push_back(min_bst.size() == max_bst.size() ? (*max_bst.cbegin() + *min_bst.cbegin()) / 2.0 : *min_bst.cbegin());
        }
    }
    return ans;
}