#include <bits/stdc++.h>

using namespace std;

// SOLUTION
vector<int> rearrangeArray(vector<int> &nums)
{
    queue<int> p{};
    queue<int> n{};

    for (int &num : nums)
        if (num < 0)
            n.push(num);
        else
            p.push(num);

    for (int i{0}, j{1}; i < nums.size() && j < nums.size(); i += 2, j += 2)
    {
        nums[i] = p.front();
        nums[j] = n.front();

        p.pop();
        n.pop();
    }

    return nums;
}