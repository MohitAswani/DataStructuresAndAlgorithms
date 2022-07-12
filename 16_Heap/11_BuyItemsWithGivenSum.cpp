#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we need to find the maximum number of items we can buy with the given sum.
 * We find the min cost item in each traversal and buy until we cannot.
 * 
 * Time complexity : O(n)+O(res*logn) (res<<n) = upper bound can be O(nlogn)
 * Auxillary space : O(n) (priority queue) (O(1) if we convert the given array to heap)
 * 
 * @param cost 
 * @param n 
 * @param sum 
 * @return int 
 */
int buyItems(int cost[],int n,int sum)
{
    priority_queue <int,vector <int>,greater<int>> pq(cost,cost+n);

    int ans=0;

    while(sum>=pq.top())
    {
        sum-=pq.top();
        ans++;
        pq.pop();
    }

    return ans;
}
int main(){
    int cost[]={1,12,5,111,200};
    int size=sizeof(cost)/sizeof(int);
    int sum=10;

    cout<<buyItems(cost,size,sum)<<endl;
    return 0;
}