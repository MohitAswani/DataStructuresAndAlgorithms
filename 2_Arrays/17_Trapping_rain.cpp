#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief In this solution we traverse through the whole array on both sides and find the left max and right max.
 * Then we subtract each element from the minimum of these. This gives us the water trapped in that well.
 * 
 * Time complexity : O(n)
 * Space complextiy : O(1)
 * 
 * @param arr 
 */
void op(vector<ll> &arr)
{
    ll size=arr.size();
    vector <ll> lmax(size);
    vector <ll> rmax(size);
    lmax.at(0)=arr.at(0);
    for(ll i=1;i<size;i++)
    {
        lmax[i]=max(arr[i],lmax[i-1]);
    }
    rmax.at(size-1)=arr.at(size-1);
    for(ll i=size-2;i>=0;i--)
    {
        rmax[i]=max(arr[i],rmax[i+1]);
    }
    ll rain=0;
    for(ll i=0;i<size;i++)
    {
        ll temp=min(lmax[i],rmax[i]);
        rain+=temp-arr.at(i);
    }
    cout<<rain<<endl;
}
int main()
{
    vector<ll> arr{3,0,1,2,5};
    op(arr);
    return 0;
}