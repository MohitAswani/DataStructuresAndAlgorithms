#include<bits/stdc++.h>
using namespace std;
void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
}
void indegree(vector <int> adj[],int V,vector <int> &indegree)
{
    for(int i=0;i<V;i++)
    {
        for(auto x:adj[i])
        {
            indegree[x]++;
        }
    }
}
/**
 * KAHN'S BFS BASED ALGORITHM :
 * -------------------
 * 
 * Store the indegree of every vertex
 * Create a queue q
 * Add all 0 indegree vertices to the q
 * while(q is not empty)
 * {
 *      a) u=q.pop()
 *      b) print u
 *      c) For every adjacent v of u:
 *          i) Reduce indegree of v by 1
 *          ii) If indegree of v = 0 add v to the queue
 * }
 */ 
void topologicalSort(vector <int> adj[],int V)
{
    vector <int> indegreeVector(V+1);
    indegree(adj,V,indegreeVector);
    queue <int> q;
    for(int i=0;i<V;i++)
    {
        if(indegreeVector[i]==0)
        q.push(i);
    }
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(auto v:adj[u])
        {
            if(indegreeVector[v]!=0)
            indegreeVector[v]--;

            if(indegreeVector[v]==0)
            {
                q.push(v);
            }
        }
    }
}
int main(){
    int V=5;
    vector <int> adj[V];  //In this implementation we use array of vectors we can also use vector of vectors to allow flexiblity
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    topologicalSort(adj,V);
    return 0;
}