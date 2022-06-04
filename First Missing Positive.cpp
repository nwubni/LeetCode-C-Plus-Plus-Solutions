#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int firstMissingPositive(vector<int> &nums)
{
    unordered_map<int, int> nums_map{};

    for (int &num : nums)
        nums_map[num]++;

    int i{1};

    for (; i <= nums.size(); i++)
        if (!nums_map[i])
            break;

    return i;
}