#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int findLengthOfLCIS(vector<int> &nums)
{
    int ans{0};
    int count{1};

    for (int i{1}; i < nums.size(); i++)
    {
        if (nums[i - 1] < nums[i])
            count++;
        else
        {
            ans = max(ans, count);
            count = 1;
        }
    }

    return max(ans, count);
}