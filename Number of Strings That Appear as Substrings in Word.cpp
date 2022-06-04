#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int numOfStrings(vector<string> &patterns, string word)
{
    int count{0};

    for (string &pattern : patterns)
    {
        size_t found = word.find(pattern);

        if (found != string::npos)
            count++;
    }

    return count;
}