## OPEN ADDRESSING:

* Idea of open addressing is to use a single array rather than using different data structures.

* Basic requirrement : no. of slabs in hash table >= no. of keys to be inserts.

* Cache friendly.

* Multiple ways of implements: 
    1) Linear probing.
    2) Quadratic probing.
    3) Double hashing.


## INSERTION

* Eg: We use linear probing : linearly search for the next empty space when there is a collision.

    ```
    {50,51,49,16,56,15,19}

    hash=key%7.

        0   49  
        1   50
        2   51
        3   16
        4   56
        5   15
        6   19

    ```

* If we are mapping to last slot and last slot is occupied we linearly search circularly.
    ```
    {48,42,50,55,53}

        0   42
        1   50
        2   55
        3
        4   53
        5
        6   48

    For 55 we search linearly in curcular manner for empty space.
    ```


## SEARCH

* We compute hash function for the element we have to find. 
* We go to that index and compare if we find the key we are done and we return true or the corresponding value. 
* Otherwise we keep on search and we stop when : 
    1) We find the key
    2) We find an empty slot
    3) Traverse through  the whole table and are at the same index.


## DELETE

* Problem with simply making the slot empty: 

    ```
    Eg:

    insert(50).insert(51),insert(15),search(15),delete(51),search(15).
    (hash=hey%7)
    After insert 51:

    0  
    1  50
    2  51
    3  15
    4
    5
    6

    After delete 51:

    0  
    1  50
    2  
    3  15
    4
    5
    6

    ```

* So now if we search(15) we get a empty slot just before 15 and the search will stop there.

* So to deal with this we mark that slot as Deleted slot and the search must not stop at deleted slot and insert can insert at deleted slot.


## CLUSTERING (PROBLEM WITH LINEAR PROBING)

* Due to linear probing clusters are created. 
* So when k consecutive positions are filled and a new hash to be inserted then the cluster will increase by size 1 and become k+1. 
* So due to clustering every operation becomes costly.


## TO HANDLE CLUSTERING

* So this is what we were doing in linear probing : hash(key,i)=(h(key)+i)%m. Basically linear searching for empty slots.

* To prevent this we can use:

    1) Quadratic probing :

        * hash(key,i)=(h(key)+i^2)%m.

        * This leads to less clustering and hence less costly for other operations. But the problem of clustering remains. This leads to secondary clustering (linear had primary clusters).

        * Another disadvantage is that it might not find a empty slot even if there is one present.

        * So mathematically Quadratic probing will find a slot only if :

            1) Alpha(load factor)<0.5 or number of slots present > 2 * number of keys.

            2) m is prime.


    2) Double hashing

