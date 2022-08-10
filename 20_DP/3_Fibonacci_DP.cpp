#include <bits/stdc++.h>
using namespace std;

/**
 * @brief In the below function we find the values for (n-1)th and (n-2)th fibonacci number and add them.
 *
 * Time complexity : O(2^n) or theta((golden ration)^n)
 * Auxillary space : O(n)
 *
 * @param n
 * @return int
 */
int fib_recursive(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// This memo vector can be used for find fib number from 0 to 100000 in linear time

vector<int> memo(100001, -1);

/**
 * @brief We storing the result for the max value and for every value less than the max value we will get the result in O(1).
 *
 * Time complexity : theta(n) at worst and theta(1) at best as computation of values is only need once
 *
 * @param n
 * @return int
 */
int fib_dp(int n)
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