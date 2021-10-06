#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
long long factorial(ll n)
{
    if(n==1||n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}
int func(string str)
{
    int res=1;
    int n=str.length();
    ll mul=factorial(n);
    vector <ll> count(256,0);
    for(int i=0;i<n;i++)
    {
        count[str[i]]++;
    }
    for(int i=1;i<256;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=0;i<n-1;i++)
    {
        mul=mul/(n-i);
        res+=count[str[i]-1]*mul;
        for(int j=str[i];j<256;j++)
        {
            count[j]--;
        }
    }
    return res;

}
int main(){
    string str="geeksforgeeks";
    func(str);
    //cout<<func(str)<<endl;
    return 0;
}