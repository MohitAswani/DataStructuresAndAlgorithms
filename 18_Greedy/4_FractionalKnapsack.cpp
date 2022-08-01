#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

bool myComp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second / (db)a.first) > (b.second / (db)b.first);
}

/**
 * @brief In this problem we are given a knapsack and we need to find the maximum value we can store in the knapsack given the capacity provided we can store fractional values.
 *
 * Algorithm :
 *
 * 1) Calculate ratio (value/weight) for every item.
 *
 * 2) Sort all item in decreasing order of the ratio.
 *
 * 3) Initialize : res=0 , curr_cap=given_cap
 *
 * 4) Do the following for every elem I in sorted order :
 *
 *      a) if(I.weight<=curr_cap)
 *              curr_cap -= I.weight
 *              res+=I.value
 *      b) else
 *              res+=(I.value)*(curr_cap/I.weight)
 *              return res
 *
 * 5) return res
 *
 * Time complexity : O(nlogn)
 * Auxillary space : O(1)
 *
 * @param weights
 * @param knapsackCapacity
 * @return double
 */
double fractionalKnapsack(vector<pair<ll, ll>> weights, ll knapsackCapacity)
{
    sort(weights.begin(), weights.end(), myComp);

    db res = 0;
    ll curr_cap = knapsackCapacity;

    for (int i = 0; i < weights.size(); i++)
    {
        if (weights[i].first <= curr_cap)
        {
            curr_cap -= weights[i].first;
            res += weights[i].second;
        }
        else
        {
            res += weights[i].second * (curr_cap / (db)weights[i].first);
            break;
        }
    }

    return res;
}
int main()
{
    vector<pair<ll, ll>> weights = {{50, 600}, {20, 500}, {30, 400}};
    cout << fractionalKnapsack(weights, 70) << endl;
    return 0;
}