#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
void func(string &text, string &patt)
{
    //This solution is just an improvement over the naive solution when all the elements of the pattern are distinct.

    // THIS SOLUTION IS ONLY FOR DISCRETE PATTERNS

    for (int i = 0; i <= (text.length() - patt.length()); )
    {
        int j=0;
        for (j = 0; j < patt.length(); j++)
        {
            if (patt[j] != text[j + i])
            {
                break;
            }
        }
        if (j == patt.length())
        {
            cout << i << " ";
        }
        if(j==0)
        {
            i++;
        }
        else
        {
            i=i+j;
        }
    }
    cout << endl;

    //THIS SOLUTION IS ONLY TRUE WHEN ALL ELEMENTS ARE DISTINCT
    
    // Time complexity : O(length(text))
    // Auxillary space : O(1)
}
int main()
{
    string text = "ABCABCD";
    string patt = "ABCD";
    func(text, patt);
    //cout<<func(str)<<endl;
    return 0;
}