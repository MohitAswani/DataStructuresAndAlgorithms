#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Moving all the elements after the position of insertion one step to the right. Then we replace the position with the element to be inserted
 * 
 * Time complexty : O(n)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param n 
 * @param cap 
 * @param pos 
 * @param elem 
 * @return int 
 */
int op(int arr[], int n,int cap,int pos,int elem)
{
    if(n==cap)
    return -1;

    for(ll i=cap-1;i>(pos-1);i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos-1]=elem;
    return n+1;
}
int main()
{
    int arr[6] = {1,2,3,4,5,0};
    int size = 6;
    int size_n=op(arr,5,6,6,11);
    for(ll i=0;i<size_n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}