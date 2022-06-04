#include <bits/stdc++.h>

using namespace std;

// SOLUTION
bool isPathCrossing(string path)
{
    unordered_map<string, int> m{};
    int x{0}, y{0};
    m["0,0"] = 1;

    for (char &c : path)
    {
        switch (c)
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'W':
            x--;
            break;
        case 'E':
            x++;
        }

        string key = to_string(x) + "," + to_string(y);

        if (m[key])
            return true;

        m[key]++;
    }

    return false;
}