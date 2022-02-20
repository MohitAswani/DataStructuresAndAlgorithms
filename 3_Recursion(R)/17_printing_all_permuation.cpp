#include<bits/stdc++.h>
using namespace std;
/**
 * @brief In this problem we just pick one positon of the string and swap all the elements with all the elements at other positions.
 * 
 * Time complexity : O(n*n!)
 * Auxillary space : O(n)               where n is the length of the string.
 * 
 * @param s 
 * @param i 
 */
void perm(string s,int i=0)
{
    if(i==s.length()-1)
    {
        cout<<s<<endl;
        return ;
    }
    for(int j=i;j<s.length();j++)
    {
        swap(s.at(i),s.at(j));
        perm(s,i+1);
        swap(s.at(i),s.at(j));
    }
}
int main(){
    perm("MOHIT");
    return 0;
}