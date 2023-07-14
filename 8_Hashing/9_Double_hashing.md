# DOUBLE HASHING:

* hash(key,i)=(h1(key)+i*h2(key))%m.

* Advantages:

    1) If h2(key) is relatively prime to m,then it always find a free slot if there is one. (And we will not require double the size).

    2) Distributes keys more uniform than linear probing and quadratic probing making other operations less costly.

    3) No clusterring. 


* Eg: 

    ```
    hash(key,i)=(h1(key)+i*h2(key))%m.

    m=7
    h1(key)=key%7
    h2(key)=6-(key%6) (this function is used when collision occurs and this function must never return zero since then it will keep on probing the same location).
    (h2 returns values from 1 to 6).

    So for {49,63,56,52,54,48}

    For 63: there is a collision and h1=0 and i=1 and h2=3 so hash is 3%7 

    IN THE ABOVE FORMULA THE i IS THE NUMBER OF TIME WE GET COLLISION WHILE USING THE FORMULA hash(key,i)=(h1(key)+i*h2(key))%m. (Eg for 54)

    0      49
    1      
    2      54 (by 3 collisions)
    3      63 
    4      56  
    5      52
    6      48

    ```

* Why h2(key) and m should be relatively prime?

    ```
    If h2(key)=6 

    (1X6)%7=6
    (2X6)%7=5
    (3X6)%7=4
    (4X6)%7=3
    (5X6)%7=2
    (6X6)%7=1

    ```

* So this type of function will go through all the different locations of the array and empty space if there is any.


* CODE:

    ```c++
    void doubleHashingInsert(key)
    {
        if(table is full) 
            return error;
        
        probe=h1[key], offset=h2[key] (in linear probing offset is 1)

        while(table[probe] is occupied)
        {
            probe=(probe+offset)%m;
        }
        table[probe]=key;
    }
    ```

* So double hashing is generalized linear probing.


## PERFORMANCE ANALYSIS OF SEARCH:

* (For unsuccessful search)

* alpha=n/m(<=1)

* Assumption: Every probe sequence looks at a random location

* 1-alpha : fraction of the  table is empty.

* Expected number of probes requirred time we reach an empty slot : **1/(1-alpha)**

* So if alpha-->1 number of probes to search unsuccessfully is infite (which is quite bad)
