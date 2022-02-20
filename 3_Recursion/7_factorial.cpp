#include <bits/stdc++.h>
using namespace std;
/**
 * @brief 
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n) due to recursive call stack
 * 
 * @param n 
 * @param k 
 * @return int 
 */
int func(int n,int k=1)
{
    if(n==0||n==1)
    {
        return k;
    }
    return func(n-1,n*k);
}
int main()
{
    cout<<func(0)<<endl;
    return 0;
}