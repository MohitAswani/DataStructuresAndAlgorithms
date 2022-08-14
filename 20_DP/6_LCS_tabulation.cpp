#include <bits/stdc++.h>
#define memo_size 101
using namespace std;

/**
 * @brief
 *
 * Here we are doing exactly what we did in the previous two solutions , the only difference is that we do it iteratively using tabulation which saves us the auxillary space.
 *
 * dp[i][j] is the LCS of prefix of two strings from 0 to i-1 and 0 to j-1. Also here i and j denoted the length and not the indices.
 *
 * And if s1[i-1]=s2[j-1] dp[i][j]=dp[i-1][j-1]+1 else we find the max of dp[i-1][j] and dp[i][j-1].
 *
 * Time complexity : O(n*m) ( Since we traverse the 2D vector once )
 * 
 * @param s1 first string
 * @param s2 second string
 * @return int LCS value
 */
int LCS(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1]; // the dp[i][j] stores the LCS for s1[0,....i-1] and s2[0,....j-1] (prefix till j)

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    cout << LCS("abc", "abbac") << endl;
    return 0;
}