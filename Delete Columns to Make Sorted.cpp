#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int minDeletionSize(vector<string> &strs)
{
    int deletes{0};

    for (int i{0}; i < strs[0].size(); i++)
    {
        for (int j{1}; j < strs.size(); j++)
            if (strs[j][i] < strs[j - 1][i])
            {
                deletes++;
                break;
            }
    }

    return deletes;
}