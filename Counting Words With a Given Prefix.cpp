#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int prefixCount(vector<string> &words, string pref)
{
    int count{0};

    for (string &word : words)
    {
        int match{0};

        for (int i{0}; i < pref.length() && i < word.length() && word[i] == pref[i]; i++)
            match++;

        count += match == pref.length(); // match == pref.length() returns either 0 or 1
    }

    return count;
}