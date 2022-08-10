#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 *
 * In this solution dp[i][j] represent the editDistance of string s1 from 0...i-1 and string s2 from 0...j-1.
 *
 * Initially we initialize dp of [i][0] with i since edit distance of empty string and non-empty string is the length of the non-empty string.
 *
 * And we do the same string for dp[0][i].
 *
 * Then we do the same thing as we did in the recursive solution , if the characters match we take the result of the previous characters so dp[i-1][j-1].
 *
 * If the character dont match we check the result which we will get if we perform the three operations and find the minimum of them and add 1 to it.
 *
 * Time complexity : O(n*m)
 * Auxillary space : O(n*m)
 *
 * @param s1
 * @param s2
 * @return int
 */
int editDistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
}
int main()
{
    cout << editDistance("CUT", "CAT") << endl;
    return 0;
}