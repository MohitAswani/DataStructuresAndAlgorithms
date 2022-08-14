#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we are given the length of jumps we can make from the given position and we need to determine the minimum number of jumps required to reach the end position.
 * 
 * To solve this problem we find the points from where we can reach the end position and then we recursively find the position from where we can reach those points and so on.
 * 
 * And we keep on finding the minimum of all these steps.
 * 
 * Time complexity : O(n^n)
 * Auxillary space : O(n)
 * 
 * @param jumps 
 * @param n 
 * @return int 
 */
int minJumps(vector<ll> &jumps, int n)
{
    // Base case : only when the first element present in the jumps array.
    if (n == 1)
    {
        return 0;
    }

    ll res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if ((i + jumps[i]) >= (n - 1))
        {
            // find the minimum number of jumps required to reach the position from which we can reach the end.
            ll temp_res = minJumps(jumps, i + 1);

            // Case when its not possible to reach the end.
            if (temp_res != INT_MAX)
            {
                res = min(res, temp_res + 1);
            }
        }
    }

    return res;
}
int main()
{
    vector <ll> jumps={3,4,2,1,2,1};
    cout<<minJumps(jumps,jumps.size())<<endl;
    return 0;
}