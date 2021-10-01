#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;
bool func(string str1,string str2)
{
    if(str1.length()<str2.length())
    {
        return false;
    }
    int i1=0,i2=0;
    while(i1<str1.length()&&i2<str2.length())
    {
        if(str1[i1]!=str2[i2])
        {
            i1++;
        }
        else 
        {
            i1++;
            i2++;
        }
    }
    if(i2==str2.length())
    {
        return true;
    }
    else
    {
        return false;
    }
    //Time complexity : O(m+n)
    //Auxillary space : O(1)
}
int main(){
    //SubString: contigious characters
    //SubSequence: not compulsorily contigious characters.
    string str1="ABCDE";
    string str2="AED";
    cout<<func(str1,str2)<<endl;
    return 0;
}