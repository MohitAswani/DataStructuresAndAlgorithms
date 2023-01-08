#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Based on the fact that divisors of a number exist in pairs so if we find the smaller number of those pairs then there is no need to find the large ones. 
 * 
 * So if x*y=n and x<y then x*x<=n and hence x<=n^(1/2).
 * 
 * We elimenate all numbers which are divisible by 2 and 3.
 * 
 * We check that the number is not divisible by any other prime number and we generate the prime numbers to check by using the fact that prime numbers exist in the form 6*n-1 and 6*n+1. 
 * 
 * Not all 6*n-1 and 6*n+1 numbers are prime but all primes are of the form 6*n-1 and 6*n+1.
 * 
 * Time complexity : O(n^1/2)(But the complexity is less than this)
 * Auxillary space : O(1)
 * 
 * @param n 
 * @return long long 
 */
long long prime(int n)
{
    // 2 is the only even prime number.
    // 1 is neither prime nor composite.
    
    if(n==1)return 0;
    if(n==2||n==3)return 1;
    if(n%2==0||n%3==0)return 0;

    for(ll i=5;i*i<=n;i+=6)
    {
        if(n%i==0||n%(i+2)==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m;
    cin >> n;
    cout << prime(n) << endl;
    return 0;
}