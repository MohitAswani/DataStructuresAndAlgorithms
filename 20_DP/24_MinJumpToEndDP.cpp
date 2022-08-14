#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In this problem we are given the length of jumps we can make from the given position and we need to determine the minimum number of jumps required to reach the end position.
 * 
 * To solve this problem we use a dp array which stores the minimum number of steps required to reach the given index.
 * 
 * To find the value of dp[i] we check for all the values of j<i and find the minimum of all of them.
 * 
 * @param jumps 
 * @param n 
 * @return int 
 */
int minJumpsDP(vector<ll> &jumps, int n)
{
    vector <ll> dp(n,INT_MAX);

    dp[0]=0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((j+jumps[j])>=i)
            {
                if(dp[j]!=INT_MAX)
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
    }

    return dp[n-1];
}
int main()
{
    vector <ll> jumps={3,4,2,1,2,1};
    cout<<minJumpsDP(jumps,jumps.size())<<endl;
    return 0;
}