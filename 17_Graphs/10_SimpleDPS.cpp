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
void DFS_helper(vector<int> adj[], int s, vector <bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (auto v : adj[s])
    {
        if (visited[v] == false)
            DFS_helper(adj, v, visited);
    }
}
void DFS(vector<int> adj[], int v, int s)
{
    vector <bool> visited(v + 1);
    DFS_helper(adj,s,visited);
}
int main()
{
    int V = 5;
    vector<int> adj[V]; // In this implementation we use array of vectors we can also use vector of vectors to allow flexiblity
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 1);
    DFS(adj,V,0);
    return 0;
}