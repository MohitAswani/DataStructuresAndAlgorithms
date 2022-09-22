#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In this union by rank implementation of a disjoint set we do not simply do union of the two representatives.
 *
 * Instead we use ranks to decide which one is going to become child of which one.
 *
 * Rank is nothing but height of the tree.
 *
 * Idea is simple , when we do union of two elements we have representative of those two elements, then we compare their heights and since we do not want the height of the tree to grow hence we make the smaller height representative as the child of the hight height representative.
 *
 * So with the parent array we also need to maintain the rank array.
 *
 * With union by rank the time taken by both the operations is O(logn) on an average.
 * 
 */
class DisjointSet
{
    vector<ll> parent;
    vector<ll> rank;

public:
    DisjointSet(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);

            // Initial height of each node is 0
            rank.push_back(0);
        }
    }

    // This function will return the root of the tree to which it belongs to.
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return find(parent[x]);
    }

    // Compare the ranks and make the parent.
    void runion(int x, int y)
    {
        int x_reps = find(x);
        int y_reps = find(y);

        if (x_reps == y_reps)
        {
            return;
        }

        if(rank[x_reps]<rank[y_reps])
        {
            parent[x_reps]=y_reps;
        }
        else if(rank[x_reps]>rank[y_reps])
        {
            parent[y_reps]=x_reps;
        }
        else
        {
            // When rank is same we can make anyone as the parent and increase its height by 1.
            parent[y_reps] = x_reps;
            rank[x_reps]++;
        }
    }
};
int main()
{

    DisjointSet ds = DisjointSet(5);
    ds.runion(3, 4);
    ds.runion(2, 3);
    ds.runion(1, 2);

    cout << ds.find(2) << " " << ds.find(4) << endl;
    return 0;
}