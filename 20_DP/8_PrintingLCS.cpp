#include <bits/stdc++.h>
#define memo_size 101
using namespace std;

/**
 * @brief
 *
 * To print the LCS we move in the dp matrix and whenever the character match we move diagonally and when they dont we move towards the director with more value.
 * 
 * Time complexity : O(n*m)
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

    string lcs;

    int i=n,j=m;

    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            lcs=s1[i-1]+lcs;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout<<lcs<<endl;

    return dp[n][m];
}
int main()
{
    cout << LCS("abc", "abbac") << endl;
    return 0;
}