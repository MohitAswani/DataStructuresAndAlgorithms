#include <bits/stdc++.h>
#define memo_size 101
using namespace std;
int memo[memo_size][memo_size];
void init()
{
    for (int i = 0; i < memo_size; i++)
    {
        for (int j = 0; j < memo_size; j++)
        {
            memo[i][j] = -1;  //since LCS can never be -1
        }
    }
}
/**
 * @brief 
 * In this solution we first write the recursive solution. Then we store it in a memo array and since 
 every recursive call has 2 parameters we use a 2D array to store the memoization value
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

    /* Time complexity : since every cell of the 2D matrix is going to filled only once hence the 
     time complexity of this solution is O(n*m)

     Time complexity of the recursive solution was O(2^(n+m))
    */
}
int main()
{
    init();
    cout << LCS("ABCDGH", "AEDFHR");
    return 0;
}