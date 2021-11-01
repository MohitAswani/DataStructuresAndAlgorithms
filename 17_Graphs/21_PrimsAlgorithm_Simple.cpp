#include <bits/stdc++.h> 
using namespace std; 
#define V 4
#define ll long long

/**
 * SPANNING TREE : these are trees (so no cycles) which connect all the vertices directly or indirectly without cycles.
 * 
 * MINIMUM SPANNING TREE : the spanning tree with minimum sum of weights of all the edges.
 * 
 * MINIMUM SPANNING TREE PROBLEM : in this problem we will be given a weighted,undirected and connected graph and we need to find the minimum spanning 
 tree of the graph.
 *
 * PRIM'S ALGORITHM : * In this algorithm we divide the vertices in two sets.
                      * One set containing the vertices which are in MST and other set having the ones which are not.
                      * So first we select any vertex and find the edge with minimum weight connecting the vertices in MST to ones not in MST.
                      * And we keep doing till all the edges are in MST.
                      * For better understanding watch the video : "Prim's Algorithm/Minimum Spanning Tree"
 * PRIM'S ALGORITHM moves step by step and makes greedy choice at each point.
 * 
 * IMPLEMENTAION EXPLANATION : * First we take a boolean array which tells where the element at index i is included in the MST or not.
                               * We take a key array and store the store the minimum edge in this array.
                               * To implement the key part we first initialize the key as infinite. Then we initialize the key at 0 as 0.
                               * Then we find the minimum edge (which connect mst to non mst's) which is not included in the mst.
                               * Then we included the vertice connected to minimum edge to the mst.
                               * Then we uppdate the key array with the weight of the edges connect to the min edge vertices and these edges are 
                               connected to those vertices which are not in mst .
                               * For better understanding of this concept watch the lecture : "Implementation of Prim's Algorithm C++".
 * 
 */ 
int primMST(ll graph[V][V])
{
    ll res=0;
    vector <ll> key(V,INT_MAX);
    key[0]=0;
    vector <bool> mSet(V,false);

    for(int count=0;count<V;count++)  // theta(V)
    {
        int u=-1;
        for(int i=0;i<V;i++)  // theta(V)
        {
            if(mSet[i]==false&&(u==-1||key[i]<key[u]))
            {
                u=i;
            }
        }
        mSet[u]=true;
        res+=key[u];

        for(int v=0;v<V;v++)  // theta(V)
        {
            if(graph[u][v]!=0&&!mSet[v])
            {
                key[v]=min(key[v],graph[u][v]);
            }
        }
    }
    return res;

    // Time complexity : theta(V^2) 
}
int main() 
{ 
	ll graph[V][V] = { { 0, 5, 8, 0}, 
						{ 5, 0, 10, 15 }, 
						{ 8, 10, 0, 20 }, 
						{ 0, 15, 20, 0 },}; 

	cout<<primMST(graph); 

	return 0; 
} 