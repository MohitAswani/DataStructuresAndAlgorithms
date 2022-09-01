#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/**
 * @brief We create an array of upper bound size 4*n and use it to store the values of the segment tree.
 *
 * Initial values : ss=0,se=n-1,si=0
 *
 * @param arr input array
 * @param tree
 * @param ss Start index of the sum segment.
 * @param se End index of the sum segment.
 * @param si Index of the nodes in this tree array.
 * @return int
 */
int constructST(vector<int> &arr, vector<int> &tree, int ss, int se, int si)
{

    // Base case when only one value in the segment
    if (ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }

    // Dividing the segment
    int mid = (ss + se) / 2;

    // Assigning the value of sum of left and right child to the current nodes.
    // Seperating the segments to assign sum values to the two childs.
    tree[si] = constructST(arr, tree, ss, mid, 2 * si + 1) + constructST(arr, tree, mid + 1, se, 2 * si + 2);

    // Returning the current value to the parent
    return tree[si];
}

/**
 * @brief We keep on traversing the segment tree and keep on adding the sums for the cases which are within the required query range.
 * 
 * Height of tree : O(logn)
 * 
 * We never visit more than 4 nodes on any level, so we never do more than 4*logn work.
 * 
 * Time complexity : O(logn)
 * 
 * @param tree 
 * @param qs 
 * @param qe 
 * @param ss 
 * @param se 
 * @param si 
 * @return int 
 */
int getSumRec(vector<int> &tree, int qs, int qe, int ss, int se, int si)
{
    // Case when current segment range completely outside the queried range
    if (se < qs || ss > qe)
        return 0;

    // Case when current segment range inside the queried range
    if (qs <= ss && qe >= se)
        return tree[si];

    int mid = (ss + se) / 2;

    // When the above two cases dont satisfy we recursive traverse for the cases which do satisfy the above conditions.
    return getSumRec(tree, qs, qe, ss, mid, 2 * si + 1) + getSumRec(tree, qs, qe, mid + 1, se, 2 * si + 2);
}

/**
 * @brief 
 * 
 * We recursively find the segments which contains the index and update the values for those segments, also we only make changes in the nodes having sub trees.
 * 
 * Time complexity : O(logn)
 * 
 * @param ss 
 * @param se 
 * @param i 
 * @param si 
 * @param diff 
 */
void updateRec(vector<int> &tree,int ss,int se,int i,int si,int diff)
{
    // Case when the updating value not in the range
    if(i<ss||se<i) return ;

    tree[si]+=diff;

    // Case when tree contains more subtrees to be updated
    if(se>ss)
    {
        int mid=(se+ss)/2;

        updateRec(tree,ss,mid,i,2*si+1,diff);

        updateRec(tree,mid+1,se,i,2*si+2,diff);
    }
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    vector<int> tree(4 * arr.size(), 0);

    constructST(arr, tree, 0, arr.size() - 1, 0);

    for (int i = 0; i < tree.size(); i++)
        cout << tree[i] << " ";
    cout << endl;

    return 0;
}