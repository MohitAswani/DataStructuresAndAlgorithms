#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we will be given a pair of number which represent the bridges connecting two cities and we need to find the maximum number of bridges we can make so that there is no crossing.
 *
 * To solve this problem we sort the array according to the first value of pair and if the first value is same we then sort it according to the second value.
 *
 * After sorting we find the LIS of the sorted array corresponding to second values.
 * 
 * Time complexity : O(n^2) ( O(nlogn) for sorting and O(nlogn) for LIS using BS or O(n^2) for LIS using dp)
 * Auxillary space : O(n)
 * 
 * @param bridges 
 * @return int 
 */
int buildingBridges(vector<pair<ll, ll>> bridges)
{
    ll n=bridges.size();

    sort(bridges.begin(),bridges.end());

    vector <ll> lis(bridges.size(),1);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(bridges[i].second>bridges[j].second)
            {
                lis[i]=max(lis[i],lis[j]+1);
            }
        }
    }

    return *max_element(lis.begin(),lis.end());
}
int main()
{
    vector<pair<ll, ll>> bridges = {{6, 2}, {4, 3}, {2, 6}, {1, 5}, {1, 3}};
    cout<<buildingBridges(bridges)<<endl;
    return 0;
}