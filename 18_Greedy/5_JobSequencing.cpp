#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Job
{
public:
    char id;
    ll deadline;
    ll profit;
};

bool myCmp(const Job &a, const Job &b)
{
    return a.profit < b.profit;
}

/**
 * @brief Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.
 *
 * Algorithm :
 *
 * 1) Sort all jobs in decreasing order of profit.
 *
 * 2) Iterate on jobs in decreasing order of profit.For each job , do the following :
 *      a)Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in this slot and mark this slot filled.
 *
 *      b)If no such i exists, then ignore the job.
 *
 * Time complexity : O(n^2). (It can be optimized using Priority Queue(max heap)).
 * Auxillary space : O(n)
 *
 * @param arr
 */
void printJobScheduling(vector<Job> &arr)
{
    sort(arr.begin(), arr.end(), myCmp);

    vector<ll> result(arr.size());
    vector<ll> slot(arr.size(), false);

    for (ll i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = min((ll)arr.size(), arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    for (ll i = 0; i < arr.size(); i++)
    {
        if (slot[i])
            cout << arr[result[i]].id << " ";
    }

    cout << endl;
}

int main()
{
    vector<Job> arr = {{'a', 2, 100},
                       {'b', 1, 19},
                       {'c', 2, 27},
                       {'d', 1, 25},
                       {'e', 3, 15}};

    printJobScheduling(arr);
    return 0;
}