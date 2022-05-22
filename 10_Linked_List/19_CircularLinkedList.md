# Circular linked list : 

* A circular linked list is a linked list in which the last node is connected to the first node. So the next pointer of the last node points to the first node of the linked list.

* Generally the struture of a circular linked list node is similiar to singly linked list but it can also be like a doubly linked list.  

## Advantages : 

* We can traverse the whole list from any node.

* Implementation of algorithms like round robin is very easy.

* We can insert at the beginning and at the end by just maintaining one tail reference/pointer.

* To perform insertion at the beginning we just insert an element after the tail and to perform insertion at the tail we insert the element after tail and then update the tail. So both these operations can be performed in O(1) time.

* In singly linked list we can't perform insertion at end and at begin in O(1) by just maintain a tail pointer.

* Also in circular linked list we can perform delete from the beginning in O(1) by just deleting the next of tail.

* Circular linked list is used to implement queue since in queue we require insert at the beginning and delete at the end and these two operations can be perform in O(1) in circular linked list by maitaining a tail pointer.

## Disadvantages :

* Implementation of operations becomes more complex.