#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;

/**
 * @brief Just comparing the character from the beginning and from the end.
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 * 
 * @param str 
 * @return true 
 * @return false 
 */
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
}
int main(){
string str="ABBA";
    func(str);
    cout<<func(str)<<endl;
    return 0;
}