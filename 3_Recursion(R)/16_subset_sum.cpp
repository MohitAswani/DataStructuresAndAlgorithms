#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In this problem we either add current element to the subset or we dont. And if sum==0 when all the elements have been traversed then we return 1.
 * 
 * Time complexity : O(2^n).
 * Auxillary space : O(n).
 * 
 * @param arr 
 * @param n 
 * @param sum 
 * @return int 
 */
int sub_sum(int arr[],int n,int sum)
{
    if(n==0)
    {
        return (sum==0);
    }
    return sub_sum(arr,n-1,sum-arr[n-1])+sub_sum(arr,n-1,sum);
}
int main()
{
    int arr[]={10,20,15};
    int sum=25;
    cout<<"NUMBER OF SUBSETS WITH SUM "<<sum<<" ARE :"<<sub_sum(arr,sizeof(arr)/sizeof(int),sum)<<endl;
    return 0;
}