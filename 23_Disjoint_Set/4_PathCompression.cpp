#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief Path compression is an optimization technique done in find function of disjoint set data structure.
 * 
 * Time complexity with union by rank and path compression : For m operations on n elements O(m* aplha(n))
 * 
 * Alpha(n) <=4
 * 
 * Alpha(n) is inverse ackermann function.
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

            rank.push_back(0);
        }
    }

    // In find function with path compression we do two things : 1) We find the representatives 2) We might change the tree to optimize upcoming find operation.

    // This reduces the traversal path from the root to a node and hence decreasing the time required to do the operations.

    // Also this reduces the path of all the nodes from root to the node for which we call the find function.
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        parent[x]=find(parent[x]);

        return parent[x];
    }

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
            parent[y_reps] = x_reps;
            rank[x_reps]++;
        }
    }
};

int main(){
    int a;
    return 0;
}