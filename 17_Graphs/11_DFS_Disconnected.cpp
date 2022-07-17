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
 * In DFS OF disconnect graph the basics are same only difference being that we traverse all the vertices in a loop. This lead to printing all the vertices connected a given vertex and then traversal to the next disconnect vertex in the loop.
 * 
 * Eg:

            0          3
           / \         |
          /   \        4
          1---2
            DFS : 0 1 2 3 4
 *
 * In the above graph we first traverse 0,1,2 and then 3,4
 * 
 * We can also do DFS itteratively by using STACK data structure.
 */

void DFS_helper(vector<int> adj[], int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (auto v : adj[s])
    {
        if (visited[v] == false)
            DFS_helper(adj, v, visited);
    }
}
/**
 * @brief 
 * 
 * Time complexity : O(V+E) (Reason being in the DFS_helper we traverse through all the adjacency list and that will be 2*E in undirected and E in directed. The V is present for the case when all the vertices are disconnected)
 * 
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param v 
 */
void DFS(vector<int> adj[], int v)
{
    vector<bool> visited(v + 1);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            DFS_helper(adj, i, visited); 
    }

}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 1);
    DFS(adj, V);
    return 0;
}