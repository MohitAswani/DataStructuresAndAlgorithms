#include<bits/stdc++.h>
#define NIL -1
using namespace std;
/**
 * Articulation points : vertices in a graph removal of leads to creation of multiple connected components.
 * 
 * Ideas for efficient approach : * If root of DFS tree has 2 or more children then root is an articulation point.
                                  (We can solve the problem using only this approach but it will be inefficent and the 
                                  time complexity will be O(V*(V+E)).)
                                  (Also this idea is only valid for root node and not for any other nodes because nodes
                                  other than root can have back-edges but root cannot since they have no parent)
                                  ** FOR BETTER UNDERSTANDING WATCH THE VIDEO "Articulation Point" **
                                  * If a non-root node u in DFS tree has a child v such that no ancestors are reachable 
                                  from the subtree rooted with v, then u is an articulation point.
                                  ( Remember that only one such child need to exist )
                                  ( No leave node can be articulation point )
 * 
 * Implementation : * To implement this we maintain two array discovery time and low value.
                    * Discovery time is used to store the time at which DFS for u is called.
                    * Smallest discovery time reachable from u considering both types of edges (forward and backward).
                    * For root nodes we check the number of times it called DFS for its adjacent nodes if it is more 
                    than 1 then that is a articulation point.
                    * For non-root node u to be an articulation point then must exist a child v such that low[v]>=disc[u]
                    * Time complexity : O(V*E)
                    * ** WATCH THE VIDEO FOR BETTER UNDERSTANDING **
 * 
 * 
 */ 
class Graph 
{ 
	int V; 
	list<int> *adj; 
	void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]); 
public: 
	Graph(int V);  
	void addEdge(int v, int w); 
	void AP(); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); 
} 

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) 
{ 
	 
	static int time = 0; 

	int children = 0; 

	visited[u] = true; 

	disc[u] = low[u] = ++time; 

	list<int>::iterator i; 
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
	{ 
		int v = *i;

		if (!visited[v]) 
		{ 
			children++; 
			parent[v] = u; 
			APUtil(v, visited, disc, low, parent, ap); 

			low[u] = min(low[u], low[v]); 


			if (parent[u] == NIL && children > 1) 
			ap[u] = true; 
			if (parent[u] != NIL && low[v] >= disc[u]) 
			ap[u] = true; 
		} 

		else if (v != parent[u]) 
			low[u] = min(low[u], disc[v]); 
	} 
} 

void Graph::AP() 
{ 
	bool *visited = new bool[V]; 
	int *disc = new int[V]; 
	int *low = new int[V]; 
	int *parent = new int[V]; 
	bool *ap = new bool[V]; 
	
	for (int i = 0; i < V; i++) 
	{ 
		parent[i] = NIL; 
		visited[i] = false; 
		ap[i] = false; 
	} 
	
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			APUtil(i, visited, disc, low, parent, ap); 

	for (int i = 0; i < V; i++) 
		if (ap[i] == true) 
			cout << i << " "; 
} 

int main() 
{  
	cout << "Articulation points in first graph \n";
	Graph g(5); 
	g.addEdge(1, 0); 
	g.addEdge(0, 2); 
	g.addEdge(2, 1); 
	g.addEdge(0, 3); 
	g.addEdge(3, 4); 
	g.AP(); 
	
	return 0; 
} 
