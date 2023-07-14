#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;

/**
 * @brief To check if str2 can be formed by rotating str1 we simply add two str1 and find if str2 is contained in it.
 * 
 * Time complexity : Theta(n) because find is linear 
 * Auzillary space : Theta(n)
 * 
 * @param str1 
 * @param str2 
 * @return true 
 * @return false 
 */
bool func(string str1,string str2)
{
    if(str1.length()!=str2.length())
    return false;

    return ((str1+str1).find(str2)!=string::npos);
}
int main(){
    string str1="ABCD";
    string str2="CDAC";
    cout<<func(str1,str2)<<endl;
    return 0;
}