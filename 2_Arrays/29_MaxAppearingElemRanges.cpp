#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the following problem we are given some ranges and we need to find the frequency of maximum occuring element in those ranges.
 *
 * To solve the problem we make the array where we store the frequencies of all the element.
 * First of all for all the starting pts we mark one in that array.
 * And for all the end pts we mark -1 at the pt next to them.
 * Then we find the prefix sum of the array.
 *
 * This array gives us the frequency of all the occuring elements.
 * Only constraint that we need to follow is that ranges in which the element occur must be less than a particular value.
 * 
 * Time complexity : O(max(R))
 * Auxillary space : O(max(R))
 *
 * @param L
 * @param R
 */
void op(vector<ll> L, vector<ll> R)
{
    vector<int> arr(1000, 0);

    for (ll i = 0; i < L.size(); i++)
    {
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }

    ll maxi = 0;

    for (ll i = 0; i < arr.size(); i++)
    {
        arr[i] += arr[i - 1];

        if (arr[maxi] < arr[i])
        {
            maxi = i;
        }
    }

    cout << maxi << endl;
}
int main()
{
    vector<ll> L = {1, 2, 5, 15};
    vector<ll> R = {5, 8, 7, 18};
    op(L, R);
    return 0;
}