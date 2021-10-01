#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
bool func(string str)
{
    for(int i=0;i<str.length()/2;i++)
    {
        if(str[i]!=str[str.length()-i-1])
        {
            return false;
        }
    }
    return true;
    //Time complexity : O(n)
    //Space complexity : O(1)
}
int main(){
string str="ABBA";
    func(str);
    cout<<func(str)<<endl;
    return 0;
}