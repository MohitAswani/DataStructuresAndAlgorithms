#include<bits/stdc++.h>
using namespace std;
/**
 * @brief In the below problem we are simply traversing through the string and either including the character at the current index or not including it.
 * 
 * Time complexity : O(2^len(s))
 * Space complexity : O(len(s))
 * 
 * @param s 
 * @param sub 
 * @param k 
 */
void func(string s,string sub="",size_t k=0)
{
    if(k==s.length())
    {
        cout<<sub<<" ";
        return;
    }
    func(s,sub+s.at(k),k+1);
    func(s,sub,k+1);
}
int main(){
    string s="ABC";
    func(s);
    return 0;
}