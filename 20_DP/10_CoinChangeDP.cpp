#include <bits/stdc++.h>
using namespace std;

/**
 * @brief This function is used to solve the coin change problem using DP. In the recursive solution
 we are trying to find the cases to make the sum using given coins. In the DP solution do this
 using tabulation. And since the recursive solution requirres two parameters, we can use a 2D array
 for tabulation.
 *
 * In each cell of the array we are storing the number of ways to make the sum using the coins. Each cell dp[i][j] represents the number of ways to make sum i using the first j coins.
 *
 * For each cell we are first adding the cases to make the given sum using first j-1 coins. Then we check for cases which can be made using the first j coins. (Same logic as recursive solution but we are using tabulation approach).
 *
 * The above array cannot be dp[size+1][sum+1] because we will add the same cases again and again as for in the 2D loop we will go through same sum for every coin which will include the previous cases too hence we will get extra cases.
 *
 * Time complexity is O(sum*size)
 * Auxillary space is O(sum*size) : we can opptimise this by using a 2D array of 2 rows.
 * 
 * @param coins Array containing the values of the coins
 * @param size size of the array
 * @param sum Requirred sum
 * @return int Total cases with given sum using the given coins.
 */
int coinChange(int coins[], int size, int sum)
{
    int dp[sum + 1][size + 1];

    for (int i = 1; i < sum + 1; i++) // Assigning zero for first 0 coins.
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < size + 1; i++) // Assigning 1 for sum = 0 and coin = i
    {
        dp[0][i] = 1;
    }

    // Now we do the dp part

    for (int i = 1; i <= sum; i++) // this represents the current requirred sum
    {
        for (int j = 1; j <= size; j++)
        {
            dp[i][j] = dp[i][j - 1]; // cases in which the sum is formed without including the current coin / formed by j-1 coins

            if (i >= (coins[j - 1]))
            {
                // cases in which the current coin is included
                // In this case we include the cases in which the req sum is i-coin[j-1] and number of coins can be anythings
                dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
    }
    return dp[sum][size];
}
int main()
{
    int coins[] = {1, 2, 3};
    cout << coinChange(coins, 3, 4) << endl;
    return 0;
}