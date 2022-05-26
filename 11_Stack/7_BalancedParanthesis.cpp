#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief Balanced paranthesis : bracket which opened last has to close first.
 *
 * Time complexity : O(n)
 * Auxillary space : O(n)
 * @param s
 */
void balancedParanthesis(string s)
{
    stack<char> stk;

    for (auto c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            stk.push(c);
        }
        else
        {
            if (!stk.empty())   // for (()))
            {
                if (stk.top() == '(' && c == ')')
                {
                    stk.pop();
                }
                else if (stk.top() == '[' && c == ']')
                {
                    stk.pop();
                }
                else if (stk.top() == '{' && c == '}')
                {
                    stk.pop();
                }
                else
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if (stk.size() != 0)   // for ((())
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}
int main()
{
    balancedParanthesis("{}([({})])");
    return 0;
}