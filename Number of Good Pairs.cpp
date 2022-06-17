#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int numIdenticalPairs(vector<int> &nums)
{
    map<int, int> m{};

    for (int &num : nums)
        m[num]++;

    int count{0};

    for (auto &n : m)
    {
        while (n.second > 1)
        {
            count += n.second - 1;
            n.second--;
        }
    }

    return count;
}