#include <bits/stdc++.h>

using namespace std;

// SOLUTION
bool divideArray(vector<int> &nums)
{
    map<int, int> m{};

    for (int &num : nums) // Get the frequency of every element
        m[num]++;

    for (auto &n : m)
        if (n.second & 1) // Return false if the frequency of any element is not even
            return false;

    return true;
}