#include <bits/stdc++.h>
#define memo_size 101
using namespace std;
int memo[memo_size][memo_size];
/**
 * @brief
 *
 * In the recursive solution we see a lot of repeation for this problem hence we use a memo table to store the result.
 *
 * memo[i][j] denotes the lcs of string 1 from 0 to i and string 2 from 0 to j.
 *
 * Time complexity : O(n*m) (since every cell of the 2D matrix is going to filled only once hence the time complexity of this solution is O(n*m))
 *
 *
 * @param s1 first string
 * @param s2 second string
 * @param n length of first string
 * @param m length of second string
 * @return int LCS value
 */
int LCS(string s1, string s2, int n = 0, int m = 0)
{
    if (memo[n][m] == -1)
    {
        if (n == s1.length() || m == s2.length())
        {
            memo[n][m] = 0;
        }
        else if (s1[n] == s2[m])
        {
            memo[n][m] = 1 + LCS(s1, s2, n + 1, m + 1);
        }
        else
        {
            memo[n][m] = max(LCS(s1, s2, n + 1, m), LCS(s1, s2, n, m + 1));
        }
    }
    return memo[n][m];
}
int main()
{
    memset(memo, -1, sizeof(memo));
    cout << LCS("ABCDGH", "AEDFHR");
    return 0;
}