#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief This is a brute force approach to manual searching for the pattern at each index of the string.
 * 
 * Time complexity : O((n-m+1)*m)
 * Auxillary space : O(1)
 * @param text 
 * @param patt 
 */
void func(string &text, string &patt)
{
    for (int i = 0; i <= (text.length() - patt.length()); i++)
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
    }
    cout << endl;
}
int main()
{
    string text = "AAAAA";
    string patt = "AAA";
    func(text, patt);
    return 0;
}