#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    map<string, int> ruleKeys{{"type", 0}, {"color", 1}, {"name", 2}};
    int count{0};

    for (vector<string> &item : items)
        if (item[ruleKeys[ruleKey]] == ruleValue)
            count++;

    return count;
}