#include<bits/stdc++.h>
using namespace std;
/**
 * @brief To find the last occurence of a number using binary search we first find the number using simple binary search. Then we check if the next number is same as the current number. If yes then we make l=mid+1. And we keep on doing this until either the next number is not x or we reach n-1.
 * 
 * Time complexity: O(logn)
 * Space complexity: O(1).
 * 
 * @param arr 
 * @param n 
 * @param x 
 * @return int 
 */
int last_occ(int arr[],int n,int x)
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
            if(mid==(n-1)||arr[mid+1]!=arr[mid])
            return mid;
            else
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={10,10,10,10,15,15,20,20,20,100,100};
    int x=100;
    int size=sizeof(arr)/sizeof(int);
    cout<<last_occ(arr,size,x)<<endl;
    return 0;
}