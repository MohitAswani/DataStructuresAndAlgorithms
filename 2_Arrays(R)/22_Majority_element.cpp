#include <bits/stdc++.h>
#define ll long long
using namespace std;
/**
 * @brief Majority element is the one which appears more than n/2 times.(MOORE'S VOTING ALGORITHM)
 * The first part checks for the most frequently occurring element whose frequency is more than n/2 .
 * If the frequently occurring element has frequency n/2 then the first part will not return its index. It will only return the index of an element if the frequency of that element is more than n/2.
 * It does not always give the first occurrence of the majority element rather any one of its occurrences.
 * In the second part we check whether that candidate is actually a majority.
 * 
 * WORKING OF THE ALGORITHM
 ---------------------------
 * In this algorithm the array is being divided into two sets : 1) Ones which cancel out each other 2) Ones which do not.
 * So the ones which do not cancel out each other contain the majority . 
 * As the ones which do cancel out each other exist in pairs like (x1 x2), (x2 x1), (x3 x1) and hence they might occur either n/2 times or less so they really do not matter.
 * 
 * Time complexity : O(n)
 * Auxillary space : O(1)
 * 
 * This algorithm can not be used to find the most frequent element since it will be cancelled out in the first part.
 * 
 * @param arr 
 */
void op(vector<ll> &arr)
{
    // finding a candidate for majority element
    ll n = arr.size();
    ll res = 0, count = 1;
    for (ll i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    count = 0;

    // confirming if its a majority element
    for (ll i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }

    if (count > n / 2)
    {
        cout << arr[res] << endl;
        return;
    }

    cout << -1 << endl;
}
int main()
{
    vector<ll> arr{1, 2, 3, 3};
    op(arr);
    return 0;
}