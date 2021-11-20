#include <bits/stdc++.h>
using namespace std;
/**
 * @brief  Recursive solution for the problem in which we are given the sum of coins we want and 
 * the values of coins and we need find the number of cases having the sum as the given sum 
 * which can be formed using the given coins.
 * 
 * @param coins Array containing the values of the coins
 * @param size size of the array
 * @param sum Requirred sum
 * @return int Total cases with given sum using the given coins.
 */
int coinChange(int coins[], int size, int sum)
{
    if(sum==0)
    return 1;

    if(size==0)
    return 0;

    int res=coinChange(coins,size-1,sum);

    if(coins[size-1]<=sum)
    {
        res+=coinChange(coins,size,sum-coins[size-1]);
    }

    return res;
}
int main()
{
    int coins[] = {1, 2, 3};
    cout<<coinChange(coins,3,4)<<endl;
    return 0;
}