#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * @brief  A undirected graph contains cycle if a adjacent node is visited again and it not parent of current selected node.
 * 
 * In BFS we pass the parent array and check if the adjacent is the parent or not.
 * 
 * Time complexity : O(V+E)
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param V 
 */
void printGraph(vector <int> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        for(auto x:adj[i])
        cout<<x<<" ";

        cout<<endl;
    }
}
bool BFS_Helper(vector <int> adj[],int s,vector <bool> &visited,vector <int> parent)
{
    queue <int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                q.push(v);
                visited[v]=1;
                parent[v]=u;
            }
            else if(v!=parent[u])
            {
                return true;
            }
        }
    }
    return false;
}
bool BFS_dis(vector <int> adj[],int v)
{
    vector <bool> visited(v+1,false);
    vector <int> parent(v+1,-1);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            if(BFS_Helper(adj,i,visited,parent)==true)
            {
                return true;
            }
        }
    }
    return false;

   
}
int main(){
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    cout << BFS_dis(adj, V) << endl;
    return 0;
}