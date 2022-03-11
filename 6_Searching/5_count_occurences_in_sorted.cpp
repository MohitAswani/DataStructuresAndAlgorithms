#include<bits/stdc++.h>
using namespace std;
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
/**
 * @brief To count the number of occurences of a number using binary search we find the first occurence and the last occurence of the number and then we substract the two. Giving us the number of times that number occurred in the array.
 * 
 * This is method to find the occurences of a number with O(logn) timem in a sorted array without using hashing (hence O(1) auxillary space).
 * 
 * Time complexity : O(logn)
 * Auxillary space : O(1)
 * 
 * @param arr 
 * @param size 
 * @param x 
 * @return int 
 */
int count_of_occ(int arr[],int size,int x)
{
    int f=first_occ(arr,size,x);
    if(f==-1)
    return 0;

    int l=last_occ(arr,size,x);
    return l-f+1;
}
int main(){
    int arr[]={5,5,5,5,6,6,6,7,7,7,10,10,10,10};
    int x=6;
    int size=sizeof(arr)/sizeof(int);
    cout<<count_of_occ(arr,size,x);
    return 0;
}