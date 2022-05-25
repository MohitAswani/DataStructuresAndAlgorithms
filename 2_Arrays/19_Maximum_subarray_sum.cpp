#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief KADANE'S ALGORITHM : for each element we find the maximum sum of the sub-arrays ending with that element.
 * So we see a pattern where we can compare the (maximum sum of subarray ending at previous+current element) with the current element and that gives us the maximum sum till that element.
 * Then we find the maximum value among the maximum sums till a particular element.
 *
 * Time complexity : O(n)
 * Space complexity : O(1)
 * @param arr
 */
void op(vector<ll> &arr)
{
    ll size = arr.size();
    ll max_sum = arr.at(0);
    ll maxi = arr.at(0);
    for (ll i = 1; i < size; i++)
    {
        maxi = max(arr.at(i) + maxi, arr.at(i));
        max_sum = max(maxi, max_sum);
    }
    cout << max_sum << endl;
}
int main()
{
    vector<ll> arr{-6, -1, -8};
    op(arr);
    return 0;
}