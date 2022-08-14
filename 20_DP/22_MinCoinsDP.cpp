#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief We are given some number of coins and a value and we need to find the minimum number of coins using which we can make the required value.
 * 
 * Time complexity : O(n^n)
 * Auxillary space : O(n)
 * 
 * @param coins 
 * @param val 
 * @return int 
 */
int minCoinsDP(vector <int> &coins,int val)
{
    int n=coins.size();

    vector <int> dp(val+1,INT_MAX);

    dp[0]=0;

    for(int i=1;i<=val;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
            {
                int temp_res=dp[i-coins[j]];

                if(temp_res!=INT_MAX)
                {
                    dp[i]=min(dp[i],temp_res+1);
                }
            }
        }
    }

    return dp[val];
}

int main(){
    vector <int> c={9,6,5,1};
    cout<<minCoinsDP(c,11)<<endl;
    return 0;
}