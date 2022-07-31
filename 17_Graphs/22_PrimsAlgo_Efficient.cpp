#include <bits/stdc++.h>
#define ll long long
#define db double
#define INF 0x3f3f3f3f
using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// To add an edge
void addEdge(vector<pair<int, int>> adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

/**
 * @brief
 *
 * ALGORITHM :
 *
 * 1) Initialize keys of all vertices as infinite and parent of every vertex as -1.
 *
 * 2) Create an empty priority_queue pq.  Every item of pq is a pair (weight, vertex). Weight (or key) is used  as first item  of pair as first item is by default used to compare two pairs.
 *
 * 3) Initialize all vertices as not part of MST yet. We use boolean array inMST[] for this purpose. This array is required to make sure that an already considered vertex is not included in pq again. This is where Prim's implementation differs from Dijkstra. In Dijkstra's algorithm, we didn't need this array as distances always increase. We require this array here because key value of a processed vertex may decrease if not checked.
 *
 * 4) Insert source vertex into pq and make its key as 0.
 *
 * 5) While either pq doesn't become empty
 *
 * a) Extract minimum key vertex from pq. Let the extracted vertex be u.
 *
 * b) Include u in MST using inMST[u] = true.
 *
 * c) Loop through all adjacent of u and do following for every vertex v.

           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)

               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the pq
               (iv) parent[v] = u

 * 6) Print MST edges using parent array.
 *
 * 
 * 
 * Time complexity : O(E Log V))
 * Auxillary space : O(V)
 *
 * @param adj
 * @param V
 */
void primMST(vector<pair<int, int>> adj[], int V)
{

    // Create a priority queue to store vertices that are being primMST.
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    int src = 0; // taking vertex 0 as source

    // Create a vector for key and initialize all the keys as infinite
    vector<int> key(V, INF);

    // To store parent which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Insert source itself in priority queue and initialize its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;

    // Looping till pq becomes empty
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key vertex, extract it from priority queue. Vertex label is stored in second of pair (it has to be done this way to keep the vertices sorted key (key must be first item in pair)
        int u = pq.top().second;
        pq.pop();

        // Different key values for same vertex may exist in the priority queue. The one with the least key value is always processed first. Therefore, ignore the rest.
        if (inMST[u] == true)
        {
            continue;
        }

        // include the vertex in MST.
        inMST[u] = true;

        // Traverse all adjacent of u
        for (auto x : adj[u])
        {

            // Get vertex label and weight of current adjacent of u.
            int v = x.first;
            int weight = x.second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v.
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
    {
        cout << parent[i] << " - " << i << endl;
    }
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

    primMST(adj, V);

    return 0;
}