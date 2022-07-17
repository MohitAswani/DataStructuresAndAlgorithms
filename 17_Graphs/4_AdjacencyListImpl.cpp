#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v) // For undirected graph
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
int main()
{

    // In this implementation we use array of vectors we can also use vector of vectors to allow flexiblity.

    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    printGraph(adj, V);
    return 0;
}