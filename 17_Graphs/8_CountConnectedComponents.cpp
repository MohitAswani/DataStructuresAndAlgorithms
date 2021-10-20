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
void BFS_dis(vector <int> adj[],int v)
{
    int count=0;
    vector <bool> visited(v+1,false);
    for(int i=0;i<v;i++)
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