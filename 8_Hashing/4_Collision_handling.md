## Collision: 

* When two keys maps to the same hash value in the hash table.

* Birthday paradox: if there 23 ppl in a room then there is 50% prob that two ppl have same birthday, with 70 ppl it is 99.9 percent.

* If we know keys in advance, then we use perfect hashing.(advance methods)

* If we do not know keys, then we use one of the following:
    1) Chaning : we make a chain of colliding values.
    2) Open addressing: if some position is occupied we try to put the value in next unoccupied position.
        * Linear probing
        * Quadractic probing
        * Double hashing.