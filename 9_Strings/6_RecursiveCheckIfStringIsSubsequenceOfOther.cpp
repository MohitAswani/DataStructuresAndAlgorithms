#include <bits/stdc++.h>
#define ll long long
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;

/**
 * @brief We conditionally erase the last character of the string.
 *
 * Time complexity : O(m+n)
 * Auxillary space : O(m+n)
 *
 * @param str1
 * @param str2
 * @return true
 * @return false
 */
bool func(string str1, string str2)
{

    if (str2.length() == 0)
        return true;

    if (str1.length() == 0)
        return false;

    if (str1[0] == str2[0])
    {
        return func(str1.erase(0, 1), str2.erase(0, 1));
    }
    return func(str1.erase(0, 1), str2);
}
int main()
{
    string str1 = "ABCDE";
    string str2 = "ADE";
    cout << func(str1, str2) << endl;
    return 0;
}