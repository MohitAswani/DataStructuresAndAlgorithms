#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief To remove the duplicates we maintain the index of element next last new element in cntr. Since the array is sorted we always get repeating element next to each other. So whenever we encounter a new element we place at cntr position and increase the cntr by 1.
 * 
 * 
 * Time complexity : O(n) without sort / O(nlogn) with sort
 * Space complexity : O(1)
 * @param arr 
 * @param size 
 */
void op(int arr[], int size)
{
    sort(arr,arr+size); // if we donot want any element no matter its index we include this.
    ll cntr=1;
    for(ll i=1;i<size;i++)
    {
        if(arr[cntr-1]!=arr[i])
        {
            arr[cntr]=arr[i];
            cntr++;
        }
    }
    for(ll i=cntr;i<size;i++)
    {
        arr[i]=0;
    }
}
int main()
{
    int arr[] = {10,10,20,20,30,20};
    int size = sizeof(arr) / sizeof(arr[0]);
    op(arr, size);
    for (ll i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}