#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief To find the prefix sum of i th index we find the node representing sum of range (i,i) which is the (i+1) th node of the BIT.
 *
 * Then we keep on traversing its parent until we reach the root node and keep on adding the sum since they represent the sum of range of size of power of two which add up to give us the sum of range (0,n).
 *
 * Time complexity : O(logn)
 *
 * @param BIT
 * @param i
 * @return ll
 */
ll getSum(vector<ll> &BIT, ll i)
{
    i = i + 1;

    ll res = 0;

    while (i > 0)
    {
        res += BIT[i];

        // Turning off the last set bit which gives us the parent of the current index.
        i = i - i & (-i);
    }

    return res;
}

/**
 * @brief To update a value we will add the difference to all the indices of the BIT which represent the ranges containing the index to be modified.
 *
 * We obtain such indices but adding one to the last set bit.
 *
 * Time complexity : O(log(2n)) ( We go upto 2*n until the index becomes invalid and so the digits will be log(2n))
 *
 * @param arr
 * @param BIT
 * @param i
 * @param x
 */
void updateBIT(vector<ll> &arr, vector<ll> &BIT, int i, int x)
{
    int diff = x - arr[i];
    arr[i] = x;
    i = i + 1;

    while (i <= arr.size())
    {
        BIT[i] += diff;
        i = i + i & (-i);
    }
}

void constructUpdateBIT(vector<ll> &arr, vector<ll> &BIT, int i, int x)
{
    i = i + 1;

    while (i <= arr.size())
    {
        BIT[i] += x;
        i = i + i & (-i);
    }
}

/**
 * @brief We use this way to construct the BIT since its easy to implement.
 *
 * Time complexity : O(nlogn)
 *
 * @param arr
 * @return vector<ll>
 */
vector<ll> constructBIT(vector<ll> &arr)
{
    vector<ll> BIT(arr.size() + 1, 0);

    for (int i = 0; i <= arr.size(); i++)
    {
        constructUpdateBIT(arr, BIT, i, arr[i]);
    }

    return BIT;
}
int main()
{
    vector<ll> arr = {10, 20, 30, 40, 50};
    vector<ll> BIT = constructBIT(arr);

    cout << getSum(BIT, 3) << endl;

    return 0;
}