#include <bits/stdc++.h>
#define V 4
using namespace std;

/**
 * @brief
 *
 * Dijkstra's algorithm: in this algorithm we need find the minimum distance of every vertices from a given source vertex.
 * 
 * NOT FOR MIN-SPANNING TREE.
 *
 * This algorithm is quite similiar to the implemenation of Prim's algorithm (Not prim's algorithm)
 *
 * Explanation of dijkstra's algorithm :
                                         * First the distance of every vertex from the source is INT_MAX other than the source.
                                         * Then we find the minimum distance vertex in the distance array.
                                         * Then we go though all the adjacent vertices of this array and update the distances.(this operation is called RELAX)
                                         * And keep on repeating the same process until we loop through all the vertices.
 *
 *
 * Fact about dijkstra's algorithm :
                                     * Does not work if the graph contains NEGATIVE WEIGHT EDGE..
                                     * And the shortest path a given vertex might change if we add common weight to all vertices.(this due to the fact the number of edges in path might be more even if the path if shortest)
 *
 * In this algorithm we need a data structure which does min key and update key operation quickly and the perfect data structure for that is priority queue/min heap.
 *
 * Implementation : * Create an empty priority queue (min heap).
                    * dist[V]={INF,INF,....INF}
                    * dist[s]=0
                    * Insert all the distances in priority queue.
                    * while(pq is not empty)
                      {
                          u=pq.extractmin   // O(V*logV) (Complexity for while and min heap operation combined)
                          Relax all the adjacent of u that are not in pq/not fixed.  // O(E*logV) (Complexity for while and relax operation combined)
                      }
                    *
                    * Time complexity : O(V*logV)+O(E*logV)
 *
 *
 * The only issue with this implementation is that priority queue do not have update key operation in cpp.
 *
 * Time complexity : O(V^2)
 *
 * To make the algorithm more efficient we need to use adjacency list and min heap.
 *
 * Time complexity is O((V+E)*logV)
 * 
 * @param graph
 * @param src
 * @return vector<int>
 */
vector<int> dijkstra(int graph[V][V], int src)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> fin(V, false);
    vector<int> parent(V, -1);
    dist[src] = 0;

    // We run this loop V-1 times since after finalising V-1 vertices our last vertices is anyways decided.
    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (fin[i] == false && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }

        fin[u] = true;
        
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && fin[v] == false)
            {
                if (dist[v] > (dist[u] + graph[u][v]))
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << endl;
    }

    return dist;
}
int main()
{
    int graph[V][V] = {
        {0, 5, 8, 0},
        {5, 0, 10, 15},
        {8, 10, 0, 20},
        {0, 15, 20, 0},
    };

    vector<int> ans = dijkstra(graph, 0);
    for (int i = 0; i < V; i++)
        cout << ans[i] << " ";
    return 0;
}