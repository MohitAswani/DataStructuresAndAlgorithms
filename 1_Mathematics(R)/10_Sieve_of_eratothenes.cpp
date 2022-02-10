#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief The idea behind the sieve algorithm is that we create a boolean array which contains whether that index is prime or not.
 * In the algorithm we cross out all the multiples of prime numbers and then print the prime numbers using the boolean vector.
 * For the inner loop we run loop from i^2 since all the smaller composite numbers will get cancelled by (i-1),(i-2) and so on..
 * 
 * Time complexity : O(n*log(log(n)))
 * Auxilliary space : O(1)
 * 
 * @param n 
 */
void sieve(int n)
{
    vector <ll> isPrime(n+1,true);
    for(ll i=2;i<=n;i++)
    {
        if(isPrime.at(i))
        {
            cout<<i<<endl;
            for(ll j=i*i;j<=n;j=j+i)
            {
                isPrime.at(j)=false;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    sieve(n);
    return 0;
}