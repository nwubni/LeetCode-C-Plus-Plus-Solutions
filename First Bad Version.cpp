#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int firstBadVersion(int n)
{
    long left{1};
    long right{n};
    long mid{1};

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (isBadVersion(mid) && !isBadVersion(mid - 1))
            return mid;

        if (!isBadVersion(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }

    return mid;
}