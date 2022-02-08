#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Here we are given an unsorted array of non-negative numbers and we need to find if a sub-array(contigous part of array) of the given sum exists.
 * 
 * So we begin with zeros and keep on add elements to the sum until the sum becomes greater or equal to gsum.
 * If it becomes equal we have found our answer.
 * If it becomes greater we start removing the starting elements of that sub-array till the sum becomes less than gsum.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param gsum 
 */
void op(vector<ll> &arr,ll gsum)
{
    ll n = arr.size();
    ll sum=0;
    ll s=0;
    for(ll i=0;i<n;i++)
    {
        sum+=arr[i];
        while(sum>gsum&&s<i)
        {
            sum-=arr[s];
            s++;
        }
        if(sum==gsum)
        {
            cout<<"YUS"<<endl;
            return ;
        }
    }
    cout<<"NAHI"<<endl;
}
int main()
{
    vector<ll> arr{1,2,3};
    op(arr,4);
    return 0;
}