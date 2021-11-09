#include <bits/stdc++.h>
using namespace std;
int fib_recursive(int n) // time complexity : O(2^n) or theta((golden ration)^n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

vector<int> memo(100001, -1); /*this memo vector can be used for find fib number from 0 to 100000 in
                              in linear time */

int fib_dp(int n) /* time complexity is theta(n) at worst and theta(1) at best as computation of values is only need once */
{
    if (memo.at(n) == -1)
    {
        int res = -1;
        if (n == 1 || n == 0)
            res = n;
        else
            res = fib_dp(n - 1) + fib_dp(n - 2);

        memo[n] = res;
    }
    return memo[n];
}
int main()
{
    cout << fib_dp(40) << endl;
    cout << fib_dp(34) << endl;
    return 0;
}