#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Divide and conquor method to perform binary search.
 * 
 * Time complexity : O(logn)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param n 
 * @param x 
 * @return int 
 */
int binary_search(int arr[],int n,int x)
{
    int l=0;
    int r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]<x)
        {
            l=mid+1;
        }
        else if(arr[mid]>x)
        {
            r=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main(){
    int arr[]={10,15};
    int x=20;
    int size=sizeof(arr)/sizeof(int);
    cout<<binary_search(arr,size,x)<<endl;
    return 0;
}