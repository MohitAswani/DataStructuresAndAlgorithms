# Binary indexed tree / Fenwick tree :

* Used for fixed input array and multiple queries of the following types : 
    * Prefix operations (sum,product,xor,or) : find one of the above of all the elements from beginning to the given index. (O(logn))

    * Update a value. (O(logn))

* It is actually an array, but the concept is tree based.

* The difference between binary indexed tree and segment tree is that binary indexed is not a binary tree ds and nodes may have more than two children.

* Requirres O(nlogn) preprocessing time and Theta(n) auxillary space.

* To build the binary indexed tree we use update operation which is take logn time hence it takes nlogn time overall.

* We can perform all the operations of binary index tree by segment tree but segment tree is harder to implement also it takes more time since its upper bounded by 4logn and binary index tree is upper bounded by logn.

* Also segment tree requires array of size 4*n whereas binary index tree requires n+1.

* Also binary index trees can also be used for range queries. For eg : range(i,j) = prefix(i)-prefix(j).

* But we cannot use binary index tree for all the problems of segment tree eg : max min in range.

* Binary index tree is a better options.