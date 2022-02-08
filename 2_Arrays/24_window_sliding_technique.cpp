#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Here we are finding the maximum sum of k consecutive elements. 
 * We first find the sum of first k elements and then we use window sliding technique to maximise this sum
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param k 
 */
void op(vector<ll> &arr, int k)
{
    ll n = arr.size();
    ll maxi = 0, sum = 0;
    for (ll i = 0; i < k; i++)
    {
        maxi += arr[i];
    }
    sum = maxi;
    for (ll i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        maxi = max(sum, maxi);
    }
    
    cout<<maxi<<endl;
}
int main()
{
    vector<ll> arr{5, -10, 6, 90, 3};
    op(arr, 2);
    return 0;
}