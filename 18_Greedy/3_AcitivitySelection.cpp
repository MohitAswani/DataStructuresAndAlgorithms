#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

bool myComp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

/**
 * @brief In this problem we are given a set of activities and we need to find out the maximum number of activities that can happen on a single tasking machine.
 *
 * This problem is similiar to "Non overlapping intervals" (https://leetcode.com/problems/non-overlapping-intervals/) problem on Leetcode.
 *
 * To solve this problem we use the following greedy algorithm :
 *
 * 1) Sort according to finish time.
 *
 * 2) Initialize solution as first activity. (This is necessarily true and for prove watch the video).
 *
 * 3) Do following for remaining activites :
 *          a) If current activity overlaps with the last picked activity in the solution, ignore the current acitivity.
 *          b) Else add the current activity to the solution.
 *
 *
 * Time complexity : O(nlogn) (O(nlogn+n))
 * Auxillary space : O(1)
 *
 * @param activities
 * @return int
 */
int maxAcitivities(vector<pair<ll, ll>> &activities)
{
    if (activities.size() <= 0)
        return 0;

    sort(activities.begin(), activities.end(), myComp);

    int prev = 0;

    int res = 1;

    for (ll i = 1; i < activities.size(); i++)
    {
        if (activities[prev].second <= activities[i].first)
        {
            prev = i;
            res++;
        }
    }

    return res;
}
int main()
{
    vector<pair<ll, ll>> activities = {{3, 8}, {2, 4}, {1, 3}, {10, 11}};
    cout << maxAcitivities(activities) << endl;
    return 0;
}