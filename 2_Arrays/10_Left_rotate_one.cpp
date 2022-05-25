#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief We just move every element to one step left and then place the first element at the last position.
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 * 
 * @param arr 
 */
void op(vector <ll> &arr)
{
    int size=arr.size();
    int temp=arr.at(0);
    for(ll i=0;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr.at(size-1)=temp;
}
int main()
{
    vector <ll> arr{1,2,3,4,5};
    op(arr);
    for(ll i=0;i<arr.size();i++)
    {
        cout<<arr.at(i)<<" ";
    }
    cout<<endl;
    return 0;
}