#include <bits/stdc++.h>
using namespace std;
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