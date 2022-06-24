#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int binaryGap(int n)
{
    bool found_one{false};
    int dst{0};
    int apart{0};

    while (n)
    {
        if (found_one)
            apart++;

        if (n & 1)
        {
            found_one = true;
            dst = max(dst, apart);
            apart = 0;
        }

        n >>= 1;
    }

    return dst;
}