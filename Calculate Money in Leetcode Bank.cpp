#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int totalMoney(int n)
{
    int total{0};
    int week{1}, accrue{1};

    for (int i{1}; i <= n; i++)
    {
        if (i - 1 == 7 * week)
        {
            ++week;
            accrue = week;
        }

        total += accrue;
        accrue++;
    }

    return total;
}