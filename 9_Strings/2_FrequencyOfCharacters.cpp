#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;

/**
 * @brief Calculating the frequency of character by storing in a 26 size array by finding the difference of character from the ASCII value of 'a'.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * @return int 
 */
int main(){
    string str="geeksforgeeks";
    vector <ll> count(26,0);
    for(int i=0;i<str.length();i++)
    {
        count[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]>0)
        {
            cout<<(char)(i+'a')<<":"<<count[i]<<endl;
        }
    }

    return 0;
}