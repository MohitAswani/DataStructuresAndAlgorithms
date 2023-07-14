#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief This solution is just an improvement over the naive solution when all the elements of the pattern are distinct.
 * 
 * In this solution we just increament the outer loop by j when the patterns dont match (we can do this since we assumed that the elements are distinct).
 * 
 * THIS SOLUTION IS ONLY FOR DISCRETE PATTERNS
 * 
 * Time complexity : O(length(text))
 * Auxillary space : O(1)
 * 
 * @param text 
 * @param patt 
 */
void func(string &text, string &patt)
{
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
}
int main()
{
    string text = "ABCABCD";
    string patt = "ABCD";
    func(text, patt);
    return 0;
}