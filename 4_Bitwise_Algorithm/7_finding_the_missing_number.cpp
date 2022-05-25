#include<bits/stdc++.h>
using namespace std;
/**
 * @brief To find the missing element we first take the xor of all the elements of the array. Then we take the xor of all elements from 1 to n. Then xor of these two will give us the missing element since it will only be present once in the xor of these numbers.
 * 
 * Time complexity : O(n)
 * Space complexity : O(1).
 * 
 * @param arr 
 * @return int 
 */
int missing(vector <int> arr)
{
    int x=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        x=x^arr[i];
    }
    for(int i=1;i<=arr.size()+1;i++)
    {
        x=x^i;
    }
    return x;
}
int main(){
    vector <int> v;
    v={1,4,3};
    cout<<"MISSING ELEMENT IS :"<<missing(v)<<endl;
    return 0;
}