#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
bool func(string str1,string str2)
{
    if(str1.length()!=str2.length())
    return false;

    return ((str1+str1).find(str2)!=string::npos);
}
//Time complexity : Theta(n) because find is linear or  
//Auzillary space : Theta(n)
int main(){
    string str1="ABCD";
    string str2="CDAC";
    cout<<func(str1,str2)<<endl;
    return 0;
}