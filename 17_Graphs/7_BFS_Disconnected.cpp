#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector <int> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        for(auto x:adj[i])
        cout<<x<<" ";

        cout<<endl;
    }
}
/**
 * This code is similiar to the previous one the only difference being that this is also valid for disconnected graph.
 * For eg : 
                  1                       4
                /   \                    / \
               0     3                  5---6
                \   /
                  2
            BFS with source = 0 : 0 1 2 3 
 * The basics of traversal of the graph remain same the difference is that we traverse the adj list in a seperate function 
 and mentain a visited array in that. If a vertex is not visited we call the BFS for it and pass the visited array to the BFS.
 * And BFS prints all the nodes connected to the source we passed.
 * After that we traverse the list and again and repeat the above process.
 * This prints all the vertices of a graph connected or not.
*/
void BFS_Helper(vector <int> adj[],int s,vector <bool> &visited)
{
    queue <int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                q.push(v);
                visited[v]=1;
            }
        }
    }
}
// **************** THIS IS THE CASE WHEN THE GRAPH IS NOT CONNECTED AND SOURCE IS NOT***********
void BFS_dis(vector <int> adj[],int v)
{
    vector <bool> visited(v+1,false);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            BFS_Helper(adj,i,visited);
        }
    }

    // O(V+E) : since the inner loop with quene runs sum of edges (2*E in undirected , E in directed ) times and since we go through all the vertieces its O(V+E).
}
int main(){
    int V=7;
    vector <int> adj[V];  //In this implementation we use array of vectors we can also use vector of vectors to allow flexiblity
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,4,6);
    BFS_dis(adj,V);
    return 0;
}