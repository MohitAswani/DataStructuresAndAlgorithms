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
 * 
 * KAHN'S BFS BASED ALGORITHM :
 * -------------------
 * Topological sort : in this problem we consider the vertices as jobs and edges as dependencies and we sort the jobs according to the dependencies and print the onces with least dependencies first. 
 *
 * In topological sort we need to print the finishing order of the job so basically if all the nodes were to start then we need to find the order in which they would start if initial only independent nodes started. 
 * 
 * That is dependent jobes should come later and the jobs on which they are dependent come first.
 *
 * ALGORITHM
 * --------- 
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

/**
 * @brief We first find the indegree for each vertice and then add all the vertices with 0 indegree and do bfs and keep on pushing the nodes which currently have 0 indegree.
 * 
 * Time complexity : O(V+E) since its almost similiar to BFS other than the visited array which is replaced by indegree here. 
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param V 
 */
void topologicalSort(vector <int> adj[],int V)
{

    // TOPOLOGICAL SORT IS ONLY FOR ACYCLIC GRAPH AND IF THERE IS CYCLE OF DEPENDENCIES WE CANNOT FIND ITS TOPOLOGICAL SORT

    
    vector <int> indegreeVector(V+1);
    indegree(adj,V,indegreeVector);   // O(V+E)

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