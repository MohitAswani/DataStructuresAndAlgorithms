#include<bits/stdc++.h>
#define ll long long
#define rep(i,t) for(ll i=0;i<t;i++)
using namespace std;

/**
 * @brief We simply make a window and search for the anagram in that window.
 * 
 * Time complexity : O(CHAR*(N-M)+M) so O(N)
 * Auxillary space : O(CHAR)
 * 
 * @param str1 
 * @param str2 
 * @return true 
 * @return false 
 */
bool AnagramSearch(string str1,string str2)
{
    vector <ll> CT(256);
    vector <ll> CP(256);
    for(int i=0;i<str2.length();i++)
    {
        CT[str1[i]]++;
        CP[str2[i]]++;
    }

    for(int i=str2.length();i<str1.length();i++)
    {
        if(CT==CP)
        {
            return true;
        }  
        CT[str1[i]]++;
        CT[str1[i-str2.length()]]--;
    }
    return false;
}

int main(){
    cout<<AnagramSearch("geeksforgeeks","frog");
    return 0;
}