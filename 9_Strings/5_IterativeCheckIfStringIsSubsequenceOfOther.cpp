#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief 
 * SubString: contigious characters in the same order.
 * 
 * SubSequence: not compulsorily contigious characters but in the same order.
 * 
 * We just itterate through the str1 and find the character of str2 in the same order. We return true we reach the end of str2.
 *
 * Time complexity : O(m+n)
 * Auxillary space : O(1)
 *
 * @param str1
 * @param str2
 * @return true
 * @return false
 */
bool func(string str1, string str2)
{
    if (str1.length() < str2.length())
    {
        return false;
    }
    int i1 = 0, i2 = 0;
    while (i1 < str1.length() && i2 < str2.length())
    {
        if (str1[i1] != str2[i2])
        {
            i1++;
        }
        else
        {
            i1++;
            i2++;
        }
    }
    if (i2 == str2.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str1 = "ABCDE";
    string str2 = "AED";
    cout << func(str1, str2) << endl;
    return 0;
}