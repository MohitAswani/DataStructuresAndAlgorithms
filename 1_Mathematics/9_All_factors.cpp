#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
/**
 * @brief This again is based on the fact that the divisors of number exist in pairs. We can solve this problem using a single loop but since we want to print the numbers in order we use two loops.
 * 
 * Time complexity : O(n^1/2).
 * Auxillary space : O(1).
 * @param n 
 */
void factors(int n)
{
    ll i;
    for (i =  2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
            cout << n/i << endl;
    }
}
int main()
{
    factors(12);
    return 0;
}