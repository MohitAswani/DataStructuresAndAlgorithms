## CHAINING

* The idea is to maintain an array of linked list. 

* We use a hash function and using that we create a hash table which contains elements in linked list for each value of hash.

* Eg: For hash(key)=key%7 we make an array of size seven with each element of that array being a linked list header
    And we put element at position key%7.

    ``` 
        Hash table for the above linked list for following elements:
        {50,21,58,17,15,49,56,22,23,25}

        0    21->49->56
        1    50->15->22
        2    58->23
        3    17
        4    25
        5
        6
    ```

* Also the hash function must have be choosen wisely.  

## Performance of CHAINING:

* m= no. of slots in hash table.
* n= no. of keys to be inserted

* load factor alpha=n/m (this means how big we want our hash table to be)(load factor leads to trade off of space for time)(if load factor is small then we have less collision)

* For expected chain length we assume uniform dist of keys = alpha (load factor).

* So if we make a hash table of size n the alpha is 1 and hence hash function have O(1) or constant time requirrement.

* Expected time to search = O(1+alpha)

* Expected time to insert/delete = O(1+alpha)(So for alpha=1 we have O(1) for both)

## Data structures for storing chains:

1) Linked list : 
    * Search O(L),
    * delete O(L),
    * Insert O(L)
    (L being the length of a chain). 

    * Disadv : 
        * Not cache friendly (it is not storing nodes concurrently).
        * Uses extra space for storing next references and pointers.

2) Dynamic sized array (vectors in cpp, Arraylist in java): 
    * Same as above.
    * But the advantage with them is cache friendliness.

3) Self balancing BST: (AVL tree,Red black tree)
    * Search O(logL),
    * Delete O(logL),
    * Insert O(logL).
    * But self balancing BST are not cache friendly.