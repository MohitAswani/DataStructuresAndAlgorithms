#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
/**
 * Strongly connected components : the vertices which are reachable from one another are called strongly connected 
components.
 * Eg:  0->2->3<=>4
        ^ /
        |/
        1
    Strongly connected components : 0 1 2
                                    3 4
                                    These are 2 diff set of strongly connected components 
 * 
 * For undirected graph : since edges dont have direction so every vertex in the connected graph is reachable from the other.
 * 
 * Algorithm : * Order the vertices in decreasing order of finish time in DFS. (finish time = end time - start time in 
               recursion)
               * Reverse all edges
               * Do DFS of the reversed graph in the order obtained in the step1. For every vertex print all the reachable 
               vertices as one strongly connected graph
               * To understand more watch the video : "Kosaraju's Algorithm Part 1"

 *
 *
 * 
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
void reverseVertices(vector <int> adj[],int V)
{
    vector <int> adj_cpy[V];
    for(int i=0;i<V;i++)
    {
        for(auto v:adj[i])
        {
            addEdge(adj_cpy,v,i);
        }
    }
    for(int i=0;i<V;i++)
    {
        adj[i]=adj_cpy[i];
    }
}
void DFS_helper(vector<int> adj[], int s, vector <bool> &visited)
{
    visited[s] = true;
    cout<<s<<" ";
    for (auto v : adj[s])
    {
        if (visited[v] == false)
            DFS_helper(adj, v, visited);
    }
}
void KosaRaju(vector <int> adj[],int V)  // To better understand this part watch the video :"Kosaraju's Algorithm Part 2"
{
    stack <int> stck;
    DFS(adj,V,stck);
    
    reverseVertices(adj,V);  
    /* 
    The reason for doing this step is to ensure we have both way connectivity and for strongly connected the reverse 
    will have no effect. 

    Eg:     0
           / ^
          v   \
          1    |  
         /  \ /
         v   v 
         2   3   
        
        In this we get the wrong answer without step
    */
    vector <bool> visited(V+1,false);
    while(stck.empty()==false)
    {
        if(visited[stck.top()]==false)
        {
            DFS_helper(adj,stck.top(),visited);
            cout<<endl;
        }
        stck.pop();
    }

}
int main(){
    int V=6;
    vector <int> adj[V+1];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,0);
    addEdge(adj,4,5);
    addEdge(adj,5,4);
    addEdge(adj,3,4);
    KosaRaju(adj,V); 
    return 0;
}