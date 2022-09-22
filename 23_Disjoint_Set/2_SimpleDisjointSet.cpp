#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief In the simple implementation the idea is to use a parent array with size same as the number of elements.
 * 
 * We can consider disjoint set as an collection of trees or forrest.
 * 
 * The parent array tells which is the parent of the respective node and calling the find function for a node will give us the root of its respective tree.
 * 
 * Also which doing union we make the representative of one ndoes as the parent of representative of the other.
 * 
 * Worst case time complexity for both is O(n) which is when we have a chain.
 * 
 */
class DisjointSet
{
    vector <ll> parent;

    public:
    DisjointSet(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
        }
    }

    // This function will return the root of the tree to which it belongs to.
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }

        return find(parent[x]);
    }

    // Make the reps of one as the parent of another so basically making one tree as the child of anothers root.
    void munion(int x,int y)
    {
        int x_reps=find(x);
        int y_reps=find(y);

        if(x_reps==y_reps)
        {
            return ;
        }

        parent[y_reps]=x_reps;
    }
};
int main(){

    DisjointSet ds=DisjointSet(5);
    ds.munion(0,2);
    ds.munion(2,4);

    cout<<ds.find(0)<<" "<<ds.find(4)<<endl;
    return 0;
}