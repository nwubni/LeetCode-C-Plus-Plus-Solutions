#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string truncateSentence(string s, int k)
{
    int spaces{0};
    int len{0};

    for (char &c : s)
    {
        if (c == ' ')
            spaces++;

        if (spaces == k)
            break;

        len++;
    }

    return s.substr(0, len);
}