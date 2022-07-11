# Binary heap :

* Used in heap sort.

* Used in implementation of priority queue. This is its main use since priority queue is used in a lot of important algorithms.

* Two types : 1) Min heap (highest priority is assigned lowest value)
              2) Max heap (highest priority is assigned highest value).

* Binary heap is a complete binary tree (all the levels are filled except the last level and last level filled from left to right).

* Complete vs not complete : ![](2022-07-11-10-01-29.png)

* Advantage of using complete binary tree is that we can store it as array without wasting any space with proper parent child relationship.

* ![](2022-07-11-10-03-31.png)

* Left of item at i : 2*i+1

* Right of item at i : 2*i+2

* Parent of item at i : floor((i-1)/2)

* ![](2022-07-11-10-04-36.png)

* Advantage of being able to store in arrays : 1) Random access
                                               2) Cache friendly
                                               3) Tree has minimum height and operation which depend on height are faster
                                               4) Using linked data structure leads to wastage of space becuase of references.

## Min-heap :

* Complete binary tree.

* Every node has value smaller than its descendants.

* Example : ![](2022-07-11-10-07-38.png)

