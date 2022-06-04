#include <bits/stdc++.h>

using namespace std;

// SOLUTION
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m{};

    // Generate freqency of elements in nums
    for (int &num : nums)
        m[num]++;

    vector<int> freq{};
    unordered_map<int, vector<int>> group{};

    for (auto &n : m)
    {
        freq.push_back(n.second);           // Gets the frequency of elements from m
        group[n.second].push_back(n.first); // Groups elements by frequency
    }

    sort(freq.rbegin(), freq.rend()); // Sorts the frequencies in descending order - largest to smallest

    vector<int> ans{};

    // Collect the frequent values into ans
    for (int i{0}; i < k; i++)
    {
        ans.push_back(group[freq[i]].back());
        group[freq[i]].pop_back();
    }

    return ans;
}