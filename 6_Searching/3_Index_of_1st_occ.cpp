#include<bits/stdc++.h>
using namespace std;
/**
 * @brief To find the first occurence of a number using binary search we first find the number using simple binary search. Then we check if the previous number is same as the current number. If yes then we make r=mid-1. And we keep on doing this until either the previous number is not x or we reach 0.
 * 
 * Time complexity: O(logn)
 * Space complexity: O(1).
 * 
 * @param arr 
 * @param n 
 * @param x 
 * @return int 
 */
int first_occ(int arr[],int n,int x)
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
            if(mid==0||arr[mid-1]!=arr[mid])
            return mid;
            else
            r=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={10,10,10,10,15,15,20,20};
    int x=20;
    int size=sizeof(arr)/sizeof(int);
    cout<<first_occ(arr,size,x)<<endl;
    return 0;
}