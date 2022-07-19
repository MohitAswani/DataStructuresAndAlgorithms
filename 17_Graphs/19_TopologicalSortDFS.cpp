#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
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
 * 
 * To perform the topological sort with DFS we use a stack. 
 * 
 * We traverse the graph with normal adjacency list and push the vertices whose neighbour have been traversed and hence we get all nodes which have more dependencies in the bottom of the stack.
 * 
 * And the top contains less dependent nodes. 
 * 
 * So finally the stack contains dependencies in the order of their dependents.
 *
 * For better understanding see the video.
 */
void DFS_helper(vector<int> adj[], int s, vector <bool> &visited,stack <int> &stck)
{
    visited[s] = true;
    for (auto v : adj[s])
    {
        if (visited[v] == false)
            DFS_helper(adj, v, visited,stck);
    }
    stck.push(s);
}
void DFS(vector<int> adj[], int v,stack <int> &stck)
{
    vector <bool> visited(v + 1);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        DFS_helper(adj,i,visited,stck); 
    }
}
/**
 * @brief 
 * 
 * Time complexity : O(V+E)
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param v 
 */
void TopologicalSort(vector <int> adj[],int v)
{
    stack <int> stck;
    DFS(adj,v,stck);
    while(stck.empty()==false)
    {
        cout<<stck.top()<<" ";
        stck.pop();
    }
    cout<<endl;
}
int main()
{
    int V = 5;
    vector<int> adj[V]; // In this implementation we use array of vectors we can also use vector of vectors to allow flexiblity
    addEdge(adj,0,1);
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    TopologicalSort(adj,V);
    return 0;
}