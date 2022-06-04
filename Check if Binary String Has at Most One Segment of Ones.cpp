#include <bits/stdc++.h>

using namespace std;

// SOLUTION
bool checkOnesSegment(string s)
{
    bool consecutive{false};
    int count{0};

    for (char &c : s)
    {
        if (c == '1' && consecutive)
            return false;

        if (c == '1')
            count++;
        else
        {
            if (!consecutive && count > 0)
                consecutive = true;

            count = 0;
        }
    }

    return consecutive || count;
}