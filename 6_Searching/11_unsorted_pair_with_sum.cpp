#include <bits/stdc++.h>
using namespace std;
/**
 * @brief To check whether there exists a pair with sum = x in the given array we use hashing. We traverse through the array and check whether there exist x-arr[i] in the hash table.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * 
 * @param arr 
 * @param size 
 * @param x 
 * @return int 
 */
int sum(int arr[],int size,int x)
{
    vector<int> hash(size,0);
    for(int i=0;i<size;i++)
    {
        if(hash[x-arr[i]]==1)
        return 1;

        hash[arr[i]]=1;
    }
    return 0;
}
int main()
{
    int arr[] = {3,5,9,2,8,10,11};
    int size = sizeof(arr) / sizeof(int);
    cout<<sum(arr,size,177)<<endl;
    return 0;
}