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
int minCoins(vector <int> &coins,int val)
{
    if(val==0)
    {
        return 0; 
    }

    int res=INT_MAX;

    for(int i=0;i<coins.size();i++)
    {
        if(coins[i]<=val)
        {
            int temp_res=minCoins(coins,val-coins[i]);

            if(temp_res!=INT_MAX)
            {
                res=min(res,temp_res+1);
            }
        }
    }

    return res;
}

int main(){
    vector <int> c={3,4,1};
    cout<<minCoins(c,5)<<endl;
    return 0;
}