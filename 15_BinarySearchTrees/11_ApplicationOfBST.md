# Applications of BST (specially balanced) :

* To maintain sorted stream of data (or sorted set of data). 

* We can sort an array using self-balancing BST by just inserting the elements into it. But it is not prefered to use self-balancing BST for sorting as constants are higher and also it will require O(n) extra space.

* To implement doubly ended priority queue. It can do max and min in O(1) and insert and delete in O(logn).

* To solve problems like:
    a) Count smaller/greater in a stream.
    b) Floor/ceiling/greater/smaller in a stream.

* When we only want to do search,insert,delete it is preferred to use hash table.

* But if we want extra operations like maintain data in sorted form, or store smaller/greater elements then we use BST.