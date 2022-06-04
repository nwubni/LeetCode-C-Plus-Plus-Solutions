#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int finalValueAfterOperations(vector<string> &operations)
{
    int x{0};

    for (string &op : operations)
        x += (op[0] == '-' || op.back() == '-') ? -1 : 1;

    return x;
}