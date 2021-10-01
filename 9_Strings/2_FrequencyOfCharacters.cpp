#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;

void func(vector <ll> v)
{

}
int main(){
    string str="geeksforgeeks";
    vector <ll> count(26,0);
    for(int i=0;i<str.length();i++)
    {
        count[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]>0)
        {
            cout<<(char)(i+'a')<<":"<<count[i]<<endl;
        }
    }
    //Time complexity: O(n)
    return 0;
}