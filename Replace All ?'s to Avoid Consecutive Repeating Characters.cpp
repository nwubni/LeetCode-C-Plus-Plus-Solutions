#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string modifyString(string s)
{
    char replace = 'a';
    char prev{'0'};
    char next{};

    for (int i{0}; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
            next = i + 1 < s.length() ? s[i + 1] : '0';

            while (replace == prev || replace == next)
                replace = replace == 'z' ? 'a' : replace + 1;

            s[i] = replace;
            replace = replace == 'z' ? 'a' : replace + 1;
        }

        prev = s[i];
    }

    return s;
}