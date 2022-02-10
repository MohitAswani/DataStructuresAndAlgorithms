#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief To find the maximum value of arr[j]-arr[i] such that j>i we maintain a min element and keep on finding the difference with that element.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 */
void op(vector <ll> &arr)
{
    ll size=arr.size();
    ll diff=arr.at(1)-arr.at(0),mini=arr.at(0);
    for(ll i=0;i<size;i++)
    {
        diff=max(diff,(arr.at(i)-mini));
        mini=min(mini,arr.at(i));
    }
    cout<<diff<<endl;
    return ;
}
int main()
{
    vector <ll> arr{7,9,5,6,3,2};
    op(arr);
    return 0;
}