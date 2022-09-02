#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief To find the prefix sum of i th index we find the node representing sum of range (i,i) which is the (i+1) th node of the BIT.
 * 
 * Then we keep on traversing its parent until we reach the root node and keep on adding the sum since they represent the sum of range of size of power of two which add up to give us the sum of range (0,n).
 * 
 * Time complexity : O(logn)
 * 
 * @param BIT 
 * @param i 
 * @return ll 
 */
ll getSum(vector <ll> &BIT,ll i)
{
    i=i+1;

    ll res=0;

    while(i>0)
    {
        res+=BIT[i];
        i=i-i&(-i);
    }

    return res;
}
int main(){
    int a;
    // cout<<fun(a)<<endl;
    return 0;
}