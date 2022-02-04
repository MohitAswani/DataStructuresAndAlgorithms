#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief  The number of multiples of 5 in the factorial of n is the number of zeros in it.
 * 
 * Time complexity : O(log5(n)).
 * Auxillary space : O(1)
 * 
 * @param n 
 * @return long long 
 */
long long zero_factorial(int n)
{
    ll ans = 0,cpy;
    for (ll i = 5; i <= n; i *= 5)
    {
        cpy=n;
        if(cpy/i!=0)
        ans=ans+cpy/i;
        else
        break;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << zero_factorial(n) << endl;
    return 0;
}