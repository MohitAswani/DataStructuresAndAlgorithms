#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
bool func(string str1,string str2)
{
    if(str1.length()!=str2.length())
    return 0;

    vector <ll> count(26,0);

    for(int i=0;i<str1.length();i++)
    {
        count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }

    for(int i=0;i<str1.length();i++)
    {
        if(count[i]!=0)
        return 0;
    }
    return 1;

    //Time complexity : O(n+char)
    //Auzillary space : O(char)
}
int main(){
    //Anagrams are two string which are permutation of each other.
    string str1="listen";
    string str2="silent";
    cout<<func(str1,str2)<<endl;
    return 0;
}