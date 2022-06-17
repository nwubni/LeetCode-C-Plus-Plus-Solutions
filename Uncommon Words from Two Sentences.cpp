#include <bits/stdc++.h>

using namespace std;

// SOLUTION
vector<string> uncommonFromSentences(string s1, string s2)
{
    map<string, int> m{};
    istringstream ss{s1 + " " + s2};
    string word{};

    while (ss >> word)
        m[word]++;

    vector<string> ans{};

    for (auto &n : m)
        if (n.second == 1)
            ans.push_back(n.first);

    return ans;
}