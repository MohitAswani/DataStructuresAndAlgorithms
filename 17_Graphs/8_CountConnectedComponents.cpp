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
void BFS_Helper(vector <int> adj[],int s,vector <bool> &visited)
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
            }
        }
    }
}
/**
 * @brief To count the number of connected components we see how many time the helper function is called , because once the traversal function is called it will visited the whole component and only the not connected parts will be left.
 * 
 * Time complexity : O(V+E)
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param v 
 */
void BFS_dis(vector <int> adj[],int v)
{
    int count=0;
    vector <bool> visited(v+1,false);
    for(int i=0;i<=v;i++)
    {
        if(visited[i]==false)   //this part count the connect component of a graph
        {
            BFS_Helper(adj,i,visited);
            count++;
        }
    }
    cout<<count<<endl;
}
int main(){
    int V=7;
    vector <int> adj[V]; 
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