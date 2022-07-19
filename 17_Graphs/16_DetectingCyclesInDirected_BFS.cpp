#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
            cout << x << " ";

        cout << endl;
    }
}
/**
 *
 * To detect cycle in directed graph we cannot use the undirected algorithm because it gives true for such cases : 0-->1<--2.
 *
 * In the above it will first traverse 0,1 in DFS_helper and then go to 2 in another DFS_helper and give true for 1,2 since 1 is adjacent and not parent of 2.
 *
 * So cycles are present in directed graphs if in the same call of BFS_Helper function we detect vertices which we already visited. (Or if we detect a back edges ).
 *
 * So to do this we take a temporary array called recursion call stack in which we store the visited vertices of a one call of BFS_Helper.
 *
 * If a vertices is visited and is contained in recursive call stack then it is a cycle.
 *
 */
bool BFS_Helper(vector<int> adj[], int V, int s, vector<bool> &visited)
{
    vector<bool> recCallStack(V + 1, false);
    queue<int> q;
    visited[s] = true;
    recCallStack[s] = true;
    q.push(s);
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = 1;
                recCallStack[v] = true;
            }
            else if (recCallStack[v] == true)
            {
                return true;
            }
        }
    }
    return false;
}
/**
 * @brief So basically the logic here is that if we detect a visited node in the same call of BFS helper then there is a cycle.
 * 
 * Time complexity : O(V+E)
 * Auxillary space : O(V)
 * 
 * @param adj 
 * @param v 
 * @return true 
 * @return false 
 */
bool cycleInDirected(vector<int> adj[], int v)
{
    vector<bool> visited(v + 1, false);
    vector<int> parent(v + 1, -1);
    for (int i = 0; i <= v; i++)
    {
        if (visited[i] == false)
        {
            if (BFS_Helper(adj, v, i, visited) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int V = 3;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    cout << boolalpha;
    cout << cycleInDirected(adj, V) << endl;
    cout << noboolalpha;
    return 0;
}