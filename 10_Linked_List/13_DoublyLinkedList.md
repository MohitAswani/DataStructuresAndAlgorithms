# Doubly linked list : 

## Advantages of doubly linked list :

1) Can be traversed in both directions from any node. (can go forward/backword in a browser).

2) A node can be deleted in O(1) time if the reference to the node is given. Singly linked list requires O(n) to delete a node (unless we use the tricky method in which we copy the data of the next node in the node to delete and make its as null).

3) Insert/Delete before a given node in O(1) time. But in singly linked list we can't go back hence will have to traverse the whole linked list to delete the node before it.

3) Insert/Delete from both ends can be done O(1) time by maintaining tail. Which can't be done in linked list since to delete the last node we need to get the hold of second last node.

5) Deque allows insertion and deletion from both ends and such a data structure can be easily implemented using doubly linked list.

## Disadvantages of doubly linked list :

1) Extra space for prev.

2) Code becomes more complex for doubly linked list.