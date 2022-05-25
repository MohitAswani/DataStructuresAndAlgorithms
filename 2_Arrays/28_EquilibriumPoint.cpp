#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief In this question we need to find whether an array contains an equilibrium point and if it does then print its index.
 * Equilibrium pt is a for which the sum of elements before it is same as sum of elements after it.
 * 
 * So we basically store the sum of elements before that element and find when 2 X the sum of elements before an element is equal to the total sum - current element.
 * 
 *  Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 */
void op(vector <ll> arr)
{
    ll n=arr.size();
    ll sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    ll sumi=0;
    for(ll i=0;i<n;i++)
    {
        if((2*sumi)==sum-arr[i])
        {
            cout<<"YES at "<<i+1<<endl;
            return ;
        }
        sumi+=arr[i];
    }
    cout<<"NO"<<endl;
}
int main()
{
    vector <ll> arr{3,6,-9,8,20,6,2};
    op(arr);
    return 0;
}