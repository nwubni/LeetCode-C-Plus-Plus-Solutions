#include <bits/stdc++.h>

using namespace std;

// SOLUTION

int guessNumber(int n)
{
    long num{1};
    long left{0};
    long right{n};

    while (left <= right)
    {
        num = (left + right) / 2;

        switch (guess(num))
        {
        case -1:
            right = num - 1;
            break;
        case 1:
            left = num + 1;
            break;
        case 0:
            return num;
        }
    }

    return num;
}