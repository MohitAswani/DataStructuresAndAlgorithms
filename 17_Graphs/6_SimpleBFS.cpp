#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
            cout << x << " ";

        cout << endl;
    }
}
/**
 * In graph BFS we get a source vertex , we print the friends of this vertex and then we print friends of those vertex and so on.
 *
 * For eg :
                  1
                / | \
               0  |  3
                \ | /
                  2
            BFS with source = 0 : 0 1 2 3
 *
 * Also in BFS in graph we ensure there is no repition of vertices.
 *
 * BFS in graphs is similiar to BFS in trees only difference being that in trees we cannot go from child to root but in graph we can move both ways and this can lead to repition so to prevent this we use a isVisited array and mark it true if we have visited a vertex.
 *
 * Other than that the implementation is same : select a vertex , traverse all adjacent vertices and push them into a  queue and keep doing this until the queue is empty  and all the element have been print once.
*/

/**
 * @brief
 *
 * Time complexity : O(V+E), where V is the number of nodes and E is the number of edges.
 * Auxillary space : O(V)
 *
 * @param adj
 * @param v
 * @param s
 */
void BFS(vector<int> adj[], int v, int s)
{
    // THIS ALGORITH IS VALID WHEN SOURCE GIVEN AND GRAPH CONNECTED
    vector<bool> visited(v + 1, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    BFS(adj, V, 0);
    return 0;
}