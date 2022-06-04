#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string freqAlphabets(string s)
{
    string ans{""};
    int sz = s.length();
    int take_two{0};

    for (int i{sz - 1}; i >= 0; i--)
    {
        if (take_two == 2)
        {
            ans = (char)((s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a') + ans;
            take_two = 0;
        }

        else if (!take_two && s[i] != '#')
            ans = (char)(s[i] - '0' - 1 + 'a') + ans;

        if (s[i] == '#' || take_two)
            take_two++;
    }

    return ans;
}