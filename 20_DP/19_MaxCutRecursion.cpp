#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the recursive solution we search for the maximum number of cuts that can be made for a particular value by finding the max number of cut for n-a , n-b , n-c and we add another cut to it.
 * 
 * Time complexity : O(3^n)
 * Auxillary space : O(n)
 * 
 * @param n 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int maxCuts(int n, int a, int b, int c)
{
    if (n < 0)
    {
        return -1;
    }

    if (n == 0)
    {
        return 0;
    }

    int res = max({maxCuts(n - a, a, b, c), maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)});

    if (res == -1)
    {
        return -1;
    }

    return res + 1;
}
int main()
{
    cout<<maxCuts(5,1,2,3)<<endl;
    return 0;
}
