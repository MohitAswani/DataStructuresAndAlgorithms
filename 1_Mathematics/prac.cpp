#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

// The two solutions find the GCD using euc 
ll gcd_rec(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd_rec(b,a%b);
}
ll gcd_itt(int a,int b)
{
    while(b!=0)
    {
        ll temp_a=a;
        a=b;
        b=temp_a%b;
    }
    return a;
}
int main(){
    int a,b;
    // cin>>a>>b;
    cout<<gcd_rec(30,45)<<endl;
    return 0;
}