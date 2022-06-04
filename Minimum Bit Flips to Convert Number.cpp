#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int minBitFlips(int start, int goal)
{
    int count{0};

    while (start || goal)
    {
        count += (start & 1) != (goal & 1);

        start >>= 1;
        goal >>= 1;
    }

    return count;
}