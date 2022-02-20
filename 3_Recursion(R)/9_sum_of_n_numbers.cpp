#include <bits/stdc++.h>
using namespace std;
/**
 * @brief Tail recursive solution to find the sum from 1 to n.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n) due to recursive call stack
 * 
 * @param n 
 * @param k 
 * @return int 
 */
int func(int n,int k=0)
{
    if (n == 0)
    {
        return k;
    }
    return func(n - 1,k+n);
}
int main()
{
    cout<<func(50)<<endl;
    return 0;
}