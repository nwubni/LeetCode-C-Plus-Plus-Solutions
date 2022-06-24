#include <bits/stdc++.h>

using namespace std;

// SOLUTION
string licenseKeyFormatting(string s, int k)
{
    string s2{};

    for (char &c : s)
        if (c != '-')
            s2 += toupper(c);

    int str_len = s2.length();
    int rem = str_len % k;                     // Get the remainder of s2 / k
    string ans = rem ? s2.substr(0, rem) : ""; // If rem is not zero, take the first "rem" characters and assign to ans

    for (int i{rem}; i < str_len; i += k)
        ans += (ans.length() ? "-" : "") + s2.substr(i, k); // Append k characters to ans

    return ans;
}