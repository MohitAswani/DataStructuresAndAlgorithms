#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[], int u, int v,int cost)
{
    adj[u].push_back({v,cost});
}
void BFS(vector<pair<int,int>> adj[], int v, int s)
{
    vector<bool> visited(v + 1, false);
    vector<int> distance(v + 1, INT_MAX); 
    queue<int> q;
    visited[s] = true;
    distance[s] = 0;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (visited[v.first] == false)
            {
                q.push(v.first);
                visited[v.first] = 1;
            }
            distance[v.first]=min(distance[u]+v.second,distance[v.first]);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if(distance[i]!=INT_MAX)
        cout << distance[i] << " ";
        else
        cout<<"INF"<<" ";
    }

   
}
int main()
{
    int V = 4;
    vector<pair<int,int>> adj[V];
    addEdge(adj, 0, 1,1);
    addEdge(adj, 1, 2,3);
    addEdge(adj, 2, 3,4);
    addEdge(adj, 1, 3,2);
    BFS(adj, V, 1);
    return 0;
}