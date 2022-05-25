#include<bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Based on f(n)=n*f(n-1).
 * 
 * Time complexity : O(n).
 * Auxillary space : O(n). (due to recursion stack)
 * 
 * @param n 
 * @return long long 
 */
long long factorial_rec(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*factorial_rec(n-1);
}
/**
 * @brief f(n)=1*2*3*4.....n.
 * The itterative solution is better since it takes less auxillary space.
 * 
 * Time complexity : O(n).
 * Auxillary space : O(1).
 * 
 * @param n 
 * @return long long 
 */
long long factorial_itt(int n)
{
    ll ans=1;
    for(int i=2;i<=n;i++)
    ans*=i;

    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<factorial_rec(n)<<endl;
    cout<<factorial_itt(n)<<endl;
    return 0;
}