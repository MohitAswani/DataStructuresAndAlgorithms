#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Since the divisors exist in pairs, if there is any prime divisor (other than 1 and n itself) it will exist from 2 to n^(½). 
 * Since we are dividing it completely by the prime numbers, till the time it reaches the composite number it will not remain divisible by the composite number.
 * But when our last prime factor , the largest prime factor, has only a power 1 then we fall into a case such that the number is not printed.
 * 
 * Time complexity : O(n^1/2).
 * Auxillary space : O(1).
 * @param n 
 */
void prime(int n)
{
    if (n <= 1)
    {
        cout << 1 << endl;
    }
    while (n % 2 == 0)
    {
        cout << 2 << endl;
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << endl;
        n = n / 3;
    }
    for (ll i = 5; i * i <= n; i += 6)
    {
        while(n%i==0)
        {
            cout<<i<<endl;
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2<<endl;
            n=n/(i+2);
        }
    }
    if(n>3)
    cout<<n<<endl;
}
int main()
{
    int n;
    cin >> n;
    prime(12);
    return 0;
}