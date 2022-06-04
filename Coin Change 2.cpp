#include <bits/stdc++.h>

using namespace std;

// SOLUTION
int change(int amount, vector<int> &coins)
{
    int dp[coins.size() + 1][amount + 1];

    // Initialize table
    for (int i{0}; i <= coins.size(); i++)
        for (int j{0}; j <= amount; j++)
            dp[i][j] = (j == 0) ? 1 : 0;

    for (int i{1}; i <= coins.size(); i++)
    {
        for (int j{0}; j <= amount; j++)
        {
            if (coins[i - 1] > j) // If coin value at [i - 1] is greater than j, copy and assign the value of the cell above the current location in the table. Since arrays are zero based index and i starts from 1, [i - 1] is needed to reference the correct coin value in  the coins vector
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]; // Add the value of the cell above the current location in the table to the value at (j - coins[i - 1]) before the current row position (j)
        }
    }

    return dp[coins.size()][amount];
}