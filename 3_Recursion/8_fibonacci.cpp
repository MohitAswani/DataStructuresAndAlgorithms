#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Finding the fibonacci using the formula fib(n)=fib(n-1)+fib(n-2)
 * 
 * Time complexity : O(G^n) or O(2^n) where G is the golden ratio(1.618).
 * Auxillary space : O(n) since at max only n call to the function will be present in the recursive call stack
 * 
 * @param n 
 * @return int 
 */
int func(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    else
    return func(n-1)+func(n-2);
}
int main()
{
    cout<<func(1)<<endl;
    return 0;
}