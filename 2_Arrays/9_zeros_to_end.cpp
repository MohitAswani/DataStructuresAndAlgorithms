#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief In this solution we maintain a counter for non zero elements and if a new non-zero is discovered we swap it out with the counter position.
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 * @param arr 
 * @param size 
 */
void op(int arr[], int size)
{
    ll cntr=0;
    for(ll i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[cntr],arr[i]);
            cntr++;
        }
    }
}
int main()
{
    int arr[] = {10,9,8,0,0,0,2,0,1,0,0,11};
    int size = sizeof(arr) / sizeof(arr[0]);
    op(arr, size);
    for (ll i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}