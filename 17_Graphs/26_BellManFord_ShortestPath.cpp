#include <bits/stdc++.h>
#define V 4
#define ll long long
#define inf INT_MAX
using namespace std;

/**
 * @brief
 *
 * Bellman ford algorithm: is another shortest path algorithm and the main benefit of using bellman ford is that it also works for negative weight edges and negative weight cycles.
 *
 *
 * The idea of this algorithm is to find the shortest path of edge length 1 then shortest path of edge length 2 and then that of 3 and so on till V-1 edges.
 *
 *
 * Bellman ford is dynamic programming algorithm and we build the solution in bottom up manner by using the solution for edges length i-1 to find the solution for edge length i.
 *
 * ALGORITHM :
            * We first find the shortest paths of one edge length. Then shortest paths that are of two edge length and so on.
            * We relax all the edges V-1 times.
            * So we repeat the process of relaxation of all the edges V-1 times.
            * In the first itteration we find all the shortest path of edge length 1.
            * In the second itteration we find all the shortest path of edge length 2 or 1.
            * And by this logic we will have the shortest path (having simple edges/no cycles) before or after V-1 itteration.
            * And the reason for iterating this loop V-1 times is because the maximum length of a simple path(no cycles) in a graph having V vertices cannot be more than V-1.
 *
 *
 * WATCH THE VIDEO FOR MORE DETAILS
 *
 * Time complexity : O(V*E) for adj list and O(V^3) for adj matrix
 *
 * @param graph
 * @param s
 */
void Bellman_Ford(int graph[V][V], int s)
{
    vector<ll> dist(V, inf);
    dist[s] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] != 0 && dist[v] > dist[u] + graph[u][v])
                {
                    dist[v] = dist[u] + graph[u][v]; // relax operation is to check whether we get the shortest path to v through u.
                }
            }
        }
    }

    // In case there is cycle a containing negative edge then in that case the distance will key on decreasing everytime we go through the cycle so that is special case and to point that out we use the below code.

    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && dist[v] > dist[u] + graph[u][v])
            {
                cout << "Graph contains negative weight cycle" << endl;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from source to " << i << " is " << dist[i] << endl;
    }
}
int main()
{
    int graph[V][V] = {
        {0, 1, 4, 0},
        {0, 0, -3, 2},
        {0, 0, 0, 3},
        {0, 0, 0, 0},
    };

    Bellman_Ford(graph, 0);
    return 0;
}