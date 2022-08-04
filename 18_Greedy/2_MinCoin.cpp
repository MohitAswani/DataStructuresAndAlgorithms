#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we are given an array of coins and we need to find the minimum number of coins required to make up the given amount.
 * 
 * Sort the array and find the coins required from maximum value to minimum value
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param coins 
 * @param amt 
 * @return int 
 */
int minCoins(vector <int> coins,int amt)
{
    sort(coins.begin(),coins.end(),greater<int>());

    int res=0;

    for(int i=0;i<coins.size();i++)
    {
        int num=amt/coins[i];
        res+=num;
        amt=amt-(num*coins[i]);

        if(amt==0)
        break;
    }

    return res;
}
int main(){
    int a;
    vector <int> coins={5,10,2,1};
    cout<<minCoins(coins,57)<<endl;
    return 0;
}