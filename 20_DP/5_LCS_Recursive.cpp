#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In this solution we keep on comparing the current index character. If it is equal we add 1 to the solution of lcs(m+1,n+1) else we take the maximum of lcs(m+1,n) and lcs(m,n+1).
 * 
 * Time complexity : O(2^(n+m)) (Worst case when no string matches and lcs=0)
 * Auxillary space : O(n)
 * 
 * @param s1 
 * @param s2 
 * @param m 
 * @param n 
 * @return ll 
 */
ll lcs_recursive(string s1, string s2, int m = 0, int n = 0)
{
    if (m == s1.size() || n == s2.size())
    {
        return 0;
    }

    if (s1[m] == s2[n])
    {
        return 1 + lcs_recursive(s1, s2, m + 1, n + 1);
    }

    return max(lcs_recursive(s1, s2, m + 1, n), lcs_recursive(s1, s2, m, n + 1));
}

int main()
{
    cout<<lcs_recursive("AXYQWE","ATXYUUQFGW")<<endl;
    return 0;
}