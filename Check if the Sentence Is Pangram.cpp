#include <bits/stdc++.h>

using namespace std;

// SOLUTION
bool checkIfPangram(string sentence)
{
    set<char> s{sentence.begin(), sentence.end()};

    return s.size() == 26;
}