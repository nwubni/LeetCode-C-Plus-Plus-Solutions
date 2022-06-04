#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string replaceDigits(string s)
{
    for (int i{1}; i < s.length(); i += 2)
        s[i] = ((s[i - 1] - 'a' + s[i] - '0') % 26) + 'a'; //(s[i - 1] - 'a') Converts a lower case letter to a number in the range 0(a) - 25(z). (s[i] - '0') converts a numeric character to its int equivalent. (s[i - 1] - 'a' + s[i] - '0') % 26 ensures the resulting value after advancing the character remains in the range 0 - 25. Finally adding 'a' to ((s[i - 1] - 'a' + s[i] - '0') % 26) converts the resulting value to a letter.

    return s;
}