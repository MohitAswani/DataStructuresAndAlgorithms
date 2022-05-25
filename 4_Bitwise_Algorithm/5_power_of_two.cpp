#include<bits/stdc++.h>
using namespace std;
/**
 * @brief To find whether a number is power of two or not we use the fact that n-1 will turn on all the off bits before the first on bit. And if we number is power of two taking & of n and n-1 will give zero for all numbers expect 0.
 * 
 * Time complexity : O(1)
 * Auxillary space : O(1)
 * @param n 
 * @return true 
 * @return false 
 */
bool power_of_two(int n)
{
    return (n!=0)&&((n&(n-1))==0);
}
int main(){
    cout<<boolalpha;
    cout<<power_of_two(64)<<endl;
    cout<<noboolalpha;
    return 0;
}