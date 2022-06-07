#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string mergeAlternately(string word1, string word2)
{
    int i1{0}, i2{0};
    string ans{};

    while (i1 < word1.length() || i2 < word2.length())
    {
        if (i1 < word1.length())
            ans += word1[i1++];

        if (i2 < word2.length())
            ans += word2[i2++];
    }

    return ans;
}