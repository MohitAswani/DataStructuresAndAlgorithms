#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * @brief  A undirected graph contains cycle if a adjacent node is visited again and it not parent of current selected node.
 * 
 * In DFS we pass the parent directly to the recursive call.
 * 
 * Time complexity : O(V+E) (this solution is similiar to DFS but the only difference being that we pass a parent variable to prevent the code from considering its parent as already visited node and considering its a cycle)
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param s 
 * @param visited 
 * @param parent 
 * @return true 
 * @return false 
 */
bool DFS_helper(vector<int> adj[], int s, vector<bool> &visited, int parent)
{
    visited[s] = true;
    for (auto v : adj[s])
    {
        if (visited[v] == false)
        {
            if (DFS_helper(adj, v, visited, s) == true)
            {
                return true;
            }
        }

        else if (v != parent)
            return true;
    }
    return false;
}
bool DFS(vector<int> adj[], int v)
{
    vector<bool> visited(v + 1);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            if (DFS_helper(adj, i, visited, -1) == true)
                return true;
    }
    return false;
}
int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    // addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    cout << DFS(adj, V) << endl;
    return 0;
}