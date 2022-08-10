#include<bits/stdc++.h>
using namespace std;
/**
 * @brief We need to convert one string to another using three operations : insertion,deletion,replace.
 * 
 * And we want to minimize the number of operations requirred to do the conversion.
 * 
 * So to we first check if the current characters match, if they do we move forward in both the strings.
 * 
 * If the current characters don't match we perform the three operations and find the minimum count out of them.
 * 
 * To perform insert we move forward in the second string since we insert the element which matches.
 * 
 * To perform deletion we move forward in the first string since that character wont matter not.
 * 
 * To perform replace we move forward in both the strings since both the characters match.
 * 
 * Finally if s1 becomes empty we return all the characters left in s2 to insert (s2.length-m).
 * 
 * If s2 becomes empty we return all the characters left in s1 to delete (s1.length-n).
 * 
 * Time complexity : O(3^n)
 * 
 * @param s1 
 * @param s2
 * @param n 
 * @param m
 * @return int 
 */
int editDistance(string s1,string s2,int n=0,int m=0)
{
    if(n==s1.length())
    {
        return s2.length()-m;
    }

    if(m==s2.length())
    {
        return s1.length()-n;
    }

    if(s1[n]==s2[m])  // can when the characters match
    return editDistance(s1,s2,n+1,m+1);   

    return 1+min(editDistance(s1,s2,n,m+1),min(editDistance(s1,s2,n+1,m),editDistance(s1,s2,n+1,m+1)));  
}
int main(){
    cout<<editDistance("CUT","CAT")<<endl;
    return 0;
}