#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
/**
 *
 * To detect cycle in directed graph we cannot use the undirected algorithm because it gives true for such cases : 0-->1<--2.
 *
 * In the above it will first traverse 0,1 in DFS_helper and then go to 2 in another DFS_helper and give true for 1,2 since 1 is adjacent and not parent of 2.
 *
 * So cycles are present in directed graphs if in the same recursive call of DFS_helper function we detect a vertices which we already visited in the same call of DFS_helper. (Or if we detect a back edges ).
 *
 * So to do this we take a temporary array called recursion call stack in which we store the visited vertices of a one call of DFS_helper.
 *
 * If a vertices is visited and is contained in recursive call stack then it is a cycle.
 *
 */
bool DFS_helper(vector<int> adj[], int s, vector<bool> &visited, vector<bool> &recCallStack)
{
    visited[s] = true;
    recCallStack[s] = true;
    for (auto v : adj[s])
    {
        if (visited[v] == false && DFS_helper(adj, v, visited, recCallStack))
            return true;
        else if (recCallStack[v] == true)
            return true;
    }
    recCallStack[s] = false; // we mark this as false so that it is considered only for the present recursive call.
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
    vector<bool> recCallStack(v + 1, false); // to store the vertices visited in one call of DFS_helper
    for (int i = 0; i <= v; i++)
    {
        if (visited[i] == false)
        {
            if (DFS_helper(adj, i, visited, recCallStack) == true)
            {
                return true;
            }
        }
    }

    /* Time complexity : O(V+E)
     */
    return false;
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 3, 1);
    cout << boolalpha;
    cout << cycleInDirected(adj, V) << endl;
    cout << noboolalpha;
    return 0;
}