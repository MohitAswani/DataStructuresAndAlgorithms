#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool DFS_helper(vector<int> adj[], int s, vector <bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    for (auto v : adj[s])
    {
        if (visited[v] == false)
            DFS_helper(adj, v, visited);
    }
}
void DFS(vector<int> adj[], int v)
{
    vector <bool> visited(v + 1);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        DFS_helper(adj,i,visited);  
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
    DFS(adj,V);
    return 0;
}