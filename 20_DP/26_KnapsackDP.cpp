#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In this problem we are given a set of items with their values and weights and we need to find the maximum value which we can achieve using the given contraints.
 * 
 * We use a dp vector to store and resuse the requirred values.
 * 
 * Here dp[i][j] is the maximum value which can be achieved with starting i values and knapsack capacity j.
 * 
 * To find the solution we check if the (i-1) th weight is less or equal to requirred weight. If it is not then we simply make it the value which can be achieved by considering first i-1 weights.
 * 
 * Else we find the max of this value and the value of the current weight plus the value of dp[i-1][j-wt[i-1]].
 * 
 * Time complexity : O(n*w) (this is not a polynomial solution since value of W can be very big and hence this problem is considered an NP-hard problem and in some cases the recursive solution might be better)
 * Auxillary space : O(n*w)
 * 
 * @param w 
 * @param wt 
 * @param val 
 * @param n 
 * @return int 
 */
int knapsackDP(int w, int wt[], int val[], int n)
{
    int dp[n + 1][w + 1];

    for (int i = 0; i < w + 1; i++)
        dp[0][i] = 0;

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
        }
    }

    return dp[n][w];
}
int main()
{
    int v[] = {10, 40, 30, 50};
    int w[] = {5, 4, 6, 3};

    cout << knapsackDP(10, w, v, 4) << endl;
    return 0;
}