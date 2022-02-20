#include <bits/stdc++.h>
using namespace std;
/**
 * @brief We are finding the sum of digits of a number by using modulo 10 method.
 * 
 * Time complexity : O(digits(n))
 * Auxillary space : O(digits(n)) 
 * 
 * @param n 
 * @return int 
 */
int func(int n)
{
    if(n<=9)
    {
        return n;
    }
    return n%10+func(n/10);
}
int main()
{
    cout<<func(9987)<<endl;
    return 0;
}