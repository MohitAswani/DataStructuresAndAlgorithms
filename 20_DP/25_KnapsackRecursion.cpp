#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In this problem we are given a set of items with their values and weights and we need to find the maximum value which we can achieve using the given contraints.
 *
 * We simply traverse the array from the end and consider two cases.
 *
 * Either we dont pick the current item or we pick the current item provided its value is less than the requirred value.
 *
 * Time complexity : O(2^n)
 * Auxillary space : O(n)
 *
 * @param w
 * @param wt
 * @param val
 * @param n
 * @return int
 */
int knapsack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    // Not picking the current item
    int res = knapsack(w, wt, val, n - 1);

    // Picking the current item if the weight is less than the req weight.
    if (w >= wt[n - 1])
    {
        res = max(res, knapsack(w - wt[n - 1], wt, val, n - 1) + val[n - 1]);
    }

    return res;
}
int main()
{
    int v[] = {10, 40, 30, 50};
    int w[] = {5, 4, 6, 3};

    cout << knapsack(10, w, v, 4) << endl;
    return 0;
}