#include <bits/stdc++.h>
#define ll long long
using namespace std;

void addEdge(vector<pair<ll, ll>> adj[], ll u, ll v, ll cost)
{
    adj[u].push_back({v, cost});
}
void indegree(vector<pair<ll, ll>> adj[], ll V, vector<ll> &indegree)
{
    for (ll i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x.first]++;
        }
    }
}
void topologicalSort(vector<pair<ll, ll>> adj[], ll V, vector<ll> &toposort)
{
    vector<ll> indegreeVector(V + 1);
    indegree(adj, V, indegreeVector);
    queue<ll> q;
    for (ll i = 0; i < V; i++)
    {
        if (indegreeVector[i] == 0)
            q.push(i);
    }
    while (q.empty() == false)
    {
        ll u = q.front();
        q.pop();
        toposort.push_back(u);
        for (auto v : adj[u])
        {
            if (indegreeVector[v.first] != 0)
                indegreeVector[v.first]--;

            if (indegreeVector[v.first] == 0)
            {
                q.push(v.first);
            }
        }
    }
}

/**
 * @brief
 *
 * ALGORITHM :
 *
 * 1) Initialiaze a distance array to infinite
 * 2) dist[s]=0
 * 3) Find the topo sort of the graph
 * 4) For every vertex u in the toposort
 *          i)For every adjacent v of u:
                if(dist[v]>dist[u]+weight(u,v))
                   dist[v]=dist[u]+weight(u,v)
 *
 * Reason : Since this is DIRECTED ACYCLIC graph hence there will never be a backward and forward edge on the same edge. So if we just move forward using the topo sort and keep on finding the minimum distance for each edge we get the solution.
 *
 * The toposort gives us the order in which we move from less to more dependent vertices so we can just move forward and keep on finding the minimum distance for each edge using the less dependent vertices.
 *
 * For better understanding watch the video "Shortest Path in DAG"
 * 
 * Time complexity : O(V+E)
 * Auxillary space : O(V)
 *
 * @param adj
 * @param V
 * @param s
 */
void shortestPath(vector<pair<ll, ll>> adj[], ll V, ll s)
{
    vector<ll> distance(V + 1, INT_MAX);
    vector<ll> toposort;
    distance[s] = 0;
    topologicalSort(adj, V, toposort);  // O(V+E)

    for (auto u : toposort)   // O(V+E)
    {
        for (auto v : adj[u])
        {
            distance[v.first] = min(distance[v.first], distance[u] + v.second);
        }
    }

    for (ll i = 0; i < V; i++)
    {
        cout << distance[i] << " ";
    }
}
int main()
{
    int V = 4;
    vector<pair<ll, ll>> adj[V];
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 1, 3, 2);
    shortestPath(adj, V, 1);
    return 0;
}