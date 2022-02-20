#include <bits/stdc++.h>
using namespace std;
/**
 * @brief In the below function we traversing through the string using tail recursion and finding its reverse. If the string is completely traversed we compare its reverse to the original string to check for palindrome.
 * 
 * Time complexity : O(len(s))
 * Auxillary space : O(len(s)) due to recursive call stack
 * 
 * @param s 
 * @param r 
 * @param k 
 * @return true 
 * @return false 
 */
bool func1(string s,string r="",int k=0)
{
    if(k==s.length())
    {
        if(r==s)
        return true;

        return false;
    }
    r=s.at(k)+r;
    return func1(s,r,k+1);
}
bool func2(string &s,int l,int r)
{
    if(l>=r)
    {
        return true;    
    }
    return (s.at(l)==s.at(r))&&func2(s,l+1,r-1);
}
int main()
{
    cout<<boolalpha;
    string test="ABCBA";
    cout<<func1(test)<<endl;
    cout<<func2(test,0,test.length()-1)<<endl;
    cout<<noboolalpha;
    return 0;
}