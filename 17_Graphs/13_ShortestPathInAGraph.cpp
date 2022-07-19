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
 * @brief Shortest path in a graph is found using BFS and for finding the path we take the distance of each vertice from the source and store it in a array.
 *
 * And for each newly visited adjacent vertex we add one to distance of parent from source and that is the distance of the child from the source.
 * 
 * Time complexity : O(V+E)
 * Auxillary space : O(V)
 *
 * @param adj
 * @param v
 * @param s
 */
void BFS(vector<int> adj[], int v, int s)
{
    vector<bool> visited(v + 1, false);
    vector<int> distance(v + 1, INT_MAX); // Intitalize a distance array with all the values as infinte.
    queue<int> q;
    visited[s] = true;
    distance[s] = 0; // mark the distance of the source as 0.
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = 1;
                distance[v] = distance[u] + 1; // the path through u would be the smallest or equal to smallest due to the nature of BFS.
            }
        }
    }

    for (int i = 0; i < v; i++)
        cout << distance[i] << " ";
}
int main()
{
    int V = 4;
    vector<int> adj[V]; 
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    BFS(adj, V, 0);
    return 0;
}