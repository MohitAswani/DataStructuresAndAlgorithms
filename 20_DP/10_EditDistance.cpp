#include<bits/stdc++.h>
using namespace std;
/**
 * @brief We need to convert one string to another using three operations : insertion,deletion,replace.
 * And we want to minimize the number of operations.
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
    /*
    The above return statement considers all the three possiblities of insert,replace,delete and adds 1 cost for each operation.
    */
}
int main(){
    cout<<editDistance("CAUUUUT","CAT")<<endl;
    return 0;
}