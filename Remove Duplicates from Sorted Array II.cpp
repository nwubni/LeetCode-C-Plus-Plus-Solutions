#include <bits/stdc++.h>

using namespace std;

//SOLUTION
int removeDuplicates(vector<int> &nums)
{
    int sz = nums.size();
    int removals{0};
    int freq{1};
    int prev = nums[0];

    for (int i{1}; i < sz; i++)
    {
        if (nums[i] == prev)
        {
            prev = nums[i];
            freq++;

            if (freq > 2)
            {
                nums[i] = INT_MAX;
                removals++;
            }
        }
        else
        {
            prev = nums[i];
            freq = 1;
        }
    }

    sort(nums.begin(), nums.end());

    return sz - removals;
}