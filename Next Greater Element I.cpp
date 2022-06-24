#include <bits/stdc++.h>

using namespace std;

// SOLUTION
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    map<int, int> m{};
    vector<int> ans{};

    for (int i{0}; i < nums2.size(); i++)
        m[nums2[i]] = i;

    for (int &n : nums1)
    {
        int added{false};

        for (int i{m[n] + 1}; i < nums2.size(); i++)
            if (nums2[i] > n)
            {
                ans.push_back(nums2[i]);
                added = true;
                break;
            }

        if (!added)
            ans.push_back(-1);
    }

    return ans;
}