#include <bits/stdc++.h>

using namespace std;

vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int, int> m{};

    for (int &n : nums)
        m[n]++;

    map<int, priority_queue<int>> temp{}; // Use map because order is required to store the frequency of elements and the corresponding values in a priority queue

    for (auto &p : m)
        temp[p.second].push(p.first); // Map frequency to priority_queue{by pushing elements with the same frequency arranged from largest to smallest into the queue}>

    vector<int> ans{};
    int val{};

    for (auto &p : temp)
    {
        while (!p.second.empty())
        {
            val = p.second.top(); // Get the top value in priority queue
            p.second.pop();       // Remove top value from priority queue

            for (int i{1}; i <= p.first; i++) // Push 'p.first' number of 'val's into ans vector
                ans.push_back(val);
        }
    }

    return ans;
}