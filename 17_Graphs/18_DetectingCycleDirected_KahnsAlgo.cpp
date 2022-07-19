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
 * KAHN'S ALGORITHM FOR CYCLE DECTECTION :
 * ---------------------------------------
 * 
 * In case of a cyclic graph there will be a point when the indegree of some vertices won't be zero and the queue would be empty.
 * 
 * Also in case of cycle no node can have indegree zero initially so the traversal won't even start.
 * 
 * This is because dependencies are circularly dependent on each other so there is no way to execute anyone of them.
 * 
 */ 

/**
 * @brief If the queue becomes empty but we haven't traversed all the nodes then there is a cycle.
 * 
 * Time complexity : O(V+E) since thats the complexity of Kahn's algorithm
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param V 
 * @return true 
 * @return false 
 */
bool cycleDetection(vector <int> adj[],int V)
{
    vector <int> indegreeVector(V+1);
    indegree(adj,V,indegreeVector);
    queue <int> q;
    for(int i=0;i<V;i++)
    {
        if(indegreeVector[i]==0)
        q.push(i);
    }
    int count=0;
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        count++;
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
    
    return (count!=V);
}
int main(){
    int V=5;
    vector <int> adj[V];  //In this implementation we use array of vectors we can also use vector of vectors to allow flexiblity
    addEdge(adj,0,2);
    addEdge(adj,3,0);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    cout<<boolalpha;
    cout<<cycleDetection(adj,V)<<endl;
    cout<<noboolalpha;
    return 0;
}