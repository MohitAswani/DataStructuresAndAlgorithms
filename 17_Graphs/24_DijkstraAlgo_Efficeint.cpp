#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// To add an edge
void addEdge(vector<pair<int, int>> adj[], int u, int v,
             int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

/**
 * @brief
 *
 * 1) Initialize distances of all vertices as infinite.
 *
 * 2) Create an empty priority_queue pq.  Every item of pq is a pair (weight, vertex). Weight (or distance) is used  as first item  of pair as first item is by default used to compare two pairs
 *
 * 3) Insert source vertex into pq and make its distance as 0.
 *
 * 4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq.
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do
       following for every vertex v.

           // If there is a shorter path to v
           // through u.
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)

 * 5) Print distance array dist[] to print all shortest
   paths.
 *
 *  The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V).
 * @param adj
 * @param V
 * @param src
 */
void shortestPath(vector<pair<int, int>> adj[], int V,
                  int src)
{
    // Create a priority queue to store vertices that are being preprocessed.
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Create a vector distances and initialize all the distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize its distance as 0.
    pq.push({0, src});
    dist[src] = 0;

    // Looping till priority queue becomes empty (or all distances are not finalized)
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance vertex, extract it from priority queue. Vertex label is stored in second of pair (it has to be done this way to keep the vertices sorted distance (distance must be first item in pair)

        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            int v = (*i).first;
            int weight = (*i).second;

            // If there is shortest path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances stored in dist[]
    cout << "Vertex distance from source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << " \t\t " << dist[i] << endl;
}

int main()
{
    int V = 9;
    vector<iPair> adj[V];

    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);

    return 0;
}