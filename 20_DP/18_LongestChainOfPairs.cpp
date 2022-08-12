#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we are given an array of pair and we need to select a group of pair such that for all adjacent pairs (a,b) and (c,d) b < c (no collision).
 *
 * To solve this problem we sort the array according to the first value.
 *
 * Then we find the LIS of the sorted array.
 *
 * This problem is similiar to the activity selection problem of greedy algorithm in which we found max number of acitivities which can be performed provided only one activity can happen at a time.
 *
 * Also this problem is a specific version of the building bridges problem since in this we are given that in a pair (a,b) a<b always.
 * 
 * Also this problem requires O(nlogn) for sorting and O(nlogn) for the lis with bs or O(n^2) with dp. But we can also solve this problem using greedy in which the post processing only requires O(n).
 * 
 * Time complexity : O(n^2)
 * Auxillary space : O(n)
 * 
 * @param inp
 * @return int
 */
int longestChain(vector<pair<ll, ll>> inp)
{
    ll n = inp.size();

    sort(inp.begin(), inp.end());

    vector<ll> lis(inp.size(), 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (inp[i].first > inp[j].second)
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    return *max_element(lis.begin(), lis.end());
}
int main()
{
    vector<pair<ll, ll>> inp = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << longestChain(inp) << endl;
    return 0;
}