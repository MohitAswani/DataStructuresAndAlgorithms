#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
bool func(string str1,string str2)
{
    
    if(str2.length()==0)
    return true;

    if(str1.length()==0)
    return false;

    if(str1[0]==str2[0])
    {
        return func(str1.erase(0,1),str2.erase(0,1));
    }
    return func(str1.erase(0,1),str2);
    //Time complexity : O(m+n)
    //Auxillary space : O(m+n)
}
int main(){
    //SubString: contigious characters
    //SubSequence: not compulsorily contigious characters.
    string str1="ABCDE";
    string str2="ADE";
    cout<<func(str1,str2)<<endl;
    return 0;
}