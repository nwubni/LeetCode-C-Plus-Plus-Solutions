#include <bits/stdc++.h>

using namespace std;

// SOLUTION
bool threeConsecutiveOdds(vector<int> &arr)
{
    int count{0};

    for (int &num : arr)
    {
        if (num & 1) // Bitwise operation for checking if a number is odd
            count++;
        else
            count = 0;

        if (count == 3)
            return true;
    }

    return false;
}