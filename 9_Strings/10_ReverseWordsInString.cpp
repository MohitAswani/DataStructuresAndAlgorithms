#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
string func(string str)
{
    string temp="";
    string output="";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
        {
            output=' '+temp+output;
            temp="";
        }
        else
        {
            temp=temp+str[i];
        }
    }
    output=temp+output;
    return output;
}
int main(){

    string str="a b c c c";
    cout<<func(str)<<endl;
    return 0;
}