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
 * In DFS we use recursion to traverse a graph and we print the vertex connected (usually the smaller one) to a given vertex and then go to that vertex and do the same thing. 
 * 
 * For eg : 
             0----1\   
             |    | 4
             2----3/  

            DFS with source = 0 : 0 1 3 2 4
 *
 * DFS of graph is similiar to preorder traversal of tree only difference being that we maitain a isVisited array to prevent repeatition.
 * 
 * In DFS of graph we are given a source vertex we go to that vertex and find the vertices adjacent to it. We find the smallest vertex connect to it and go to that vertex and keep on repeating the same process for non-visited vertices and after a point we visit all the vertices and recursion ends.
 */
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