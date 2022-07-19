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

void DFS_helper(vector<int> adj[], int s, vector<bool> &visited)
{
    stack<int> stck;
    stck.push(s);
    visited[s] = true;
    while (stck.empty() == false)
    {
        int u=stck.top();
        cout << u << " ";
        stck.pop();
        for (auto it=adj[u].rbegin();it!=adj[u].rend();it++)
        {
            if (visited[*it] == false)
            {
                stck.push(*it);
                visited[*it]=1;
            }
        }
    }
}
/**
 * @brief For the iterative solution we use stack for pushing the elements. Also we push the elements in reverse order in the stack .i.e bigger to smaller so that the smaller elements are popped first.
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
    for (int i = 0; i <= v; i++)
    {
        if (visited[i] == false)
            DFS_helper(adj, i, visited); 
    }
}
int main()
{
    int V = 4;
    vector<int> adj[V]; 
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    DFS(adj, V);
    return 0;
}