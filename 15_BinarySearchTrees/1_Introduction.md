# Binary search tree: 

* This is data structure which is used for most efficient implementation of search, insert, delete , find closest element and sorted traversal.

* A balanced binary search has time complexity O(logn) for search ,insert, delete, find closest. Also it has O(n) for sorted traversal.

* These values are only for a balanced BST , if the tree is unbalanced then the time complexity will be the height of BST.

* ![](2022-06-26-10-54-27.png)

* ![](2022-06-26-10-54-43.png)

## Theory :

* Binary search tree is setup in such a way that when we are searching an item we can almost skip half of the items.

* Idea is based on binary search algorithm.

* For every node, keys in left side are smaller and keys in right side are greater.

* All keys are typically considered as distant.

* Like linked list, it is a linked data structure. So we have no memory limit and can insert as many elements as we want but the disadvantage is that we are not cache friendly.

* Implemented in C++ as map,set,multimap,multiset (in particular self-balancing BST).And in java as treeset and treemap.

* ![](2022-06-26-11-02-47.png)

* ![](2022-06-26-11-03-00.png)

* Most of the operations of BST like search,insert,delete and finding the closest are O(h).

## Search in BST:

* Need to return boolean for key with the root of a BST given.

* We compare the value to be search with the value of the node and move left or right accordingly.

* If we hit a null node, then we return false.

## Insert in BST:

* If the node is not present in the BST we insert it at the leaf.

* If the tree is null the inserted value becomes the root.

* If the node is present then we don't do anything.