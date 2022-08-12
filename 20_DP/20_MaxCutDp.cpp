#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the dp solution we search for the maximum number of cuts that can be made for a particular value by finding the max number of cut for n-a , n-b , n-c which are stored in the dp vector and we add another cut to it.
 *
 * Time complexity : O(n)
 * Auxillary space : O(n)
 *
 * @param n
 * @param a
 * @param b
 * @param c
 * @return int
 */
int maxCuts(int n, int a, int b, int c)
{
    vector<ll> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);
        if (i - b >= 0)
            dp[i] = max(dp[i], dp[i - b]);
        if (i - c >= 0)
            dp[i] = max(dp[i], dp[i - c]);

        if (dp[i] != -1)
            dp[i]++;
    }

    return dp[n];
}
int main()
{
    cout << maxCuts(5, 1, 2, 3) << endl;
    return 0;
}
