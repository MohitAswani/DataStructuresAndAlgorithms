#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief In this problem we need to find the maximum profit we can make by buying and selling stocks at the given prices.
 * The idea behind this approach is that we buy the stock at every local minima and sell it at the next maxima as we move in the graph from left to right.
 * So if arr[j]>arr[j-1] just add arr[j]-arr[j-1] to profit.So we just need to add the prices going up (and the addition is cumulative).
 * We use this approach because we only need to find the profit.
 *
 * Time complexity : O(n)
 * Space complextiy : O(1)
 * 
 * @param arr
 */
void op(vector<ll> &arr)
{
    ll size = arr.size();
    ll profit = 0;
    for (ll i = 0; i < size - 1; i++)
    {
        if (arr.at(i) < arr.at(i + 1))
        {
            profit += arr.at(i + 1) - arr.at(i);
        }
    }
    cout << profit << endl;
}
int main()
{
    vector<ll> arr{1, 5, 3, 1, 2, 8};
    op(arr);
    return 0;
}