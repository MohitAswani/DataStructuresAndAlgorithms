#include <bits/stdc++.h>
using namespace std;
#define V 4
#define ll long long

/**
 * @brief
 *
 * SPANNING TREE : these are trees (so no cycles) which connect all the vertices directly or indirectly without cycles.
 *
 * MINIMUM SPANNING TREE : the spanning tree with minimum sum of weights of all the edges.
 *
 * MINIMUM SPANNING TREE PROBLEM : in this problem we will be given a weighted,undirected and connected graph and we need to find the minimum spanning tree of the graph. (every MST has V-1 edges)
 *
 * PRIM'S ALGORITHM : * In this algorithm we divide the vertices in two sets.
                      * One set containing the vertices which are in MST and other set having the ones which are not.
                      * So first we select any vertex and find the edge with minimum weight connecting the vertices in MST to ones not in MST.
                      * And we keep doing till all the vertices are in MST.
                      * For better understanding watch the video : "Prim's Algorithm/Minimum Spanning Tree"
                      * PRIM'S ALGORITHM moves step by step and makes greedy choice at each point.
 *
 * 
 * IMPLEMENTAION EXPLANATION :  * First we take a boolean array which tells where the element at index i is included in the MST or not.
                                * We take a key array and store the edges of min length connecting mst to non-mst in this array.
                                * To implement the key part we first initialize the key as infinite. Then we initialize the key at 0 as 0.
                                * Then we find the minimum edge (which connect mst to non mst's) which is not included in the MST.
                                * Then we included the vertice connected to minimum edge to the mst.
                                * Then we update the key array with the weight of the edges connecting the min edge vertice with vertices which are not in mst .
                                * For better understanding of this concept watch the lecture : "Implementation of Prim's Algorithm C++".
 *
 * 
 * Time complexity : theta(V^2) (We can make the time complexity of this algorithm = O((V+E)logV) by using a adjacency list and a priority_queue for key.)
 *
 * Auxillary space : O(V)
 *
 * @param graph
 * @return int
 */
int primMST(ll graph[V][V])
{
    ll res = 0;
    vector<ll> key(V, INT_MAX);
    vector<bool> mSet(V, false);
    vector<ll> parent(V, -1);
    key[0] = 0;

    for (int count = 0; count < V; count++) // theta(V)
    {
        int u = -1;
        for (int i = 0; i < V; i++) // theta(V)
        {
            if (mSet[i] == false && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mSet[u] = true;
        res += key[u];

        for (int v = 0; v < V; v++) // theta(V)
        {
            if (graph[u][v] != 0 && !mSet[v])
            {
                if(graph[u][v]<key[v])
                {
                    key[v]=graph[u][v];
                    parent[v]=u;
                }
            }
        }
    }

    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << endl;
    }
    return res;
}
int main()
{
    ll graph[V][V] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };

    cout << primMST(graph);

    return 0;
}