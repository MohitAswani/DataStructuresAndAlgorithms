<h1><u><b> Trie data structure </b></u></h2>

Trie is a data structure which is used to implement dictionaries where we need to perform the following operations efficiently:

1) Search

2) Insert 

3) Delete

4) Prefix search : to search the words which start with a given prefix. Eg: For Dictionary{"geek","geeks","bat","bad"} prefix search of "gee" gives us 
                   {"geek","geeks"}.

5) Lexicographical ordering of words : if we want to arrange the words lexiographically we use the trie data structure.


<h1><u><b> Comparision with hashing </b></u></h1>

1) Search : trie takes theta(word_len) time in worst case whereas hashing takes theta(word_len) on average as it takes time to calculate the hash value and still there can be collision so the worst is case has more complexity. 

2) Insert : trie takes theta(word_len) time in worst case whereas hashing takes theta(word_len) on average.

3) Delete : trie takes theta(word_len) time in worst case whereas hashing takes theta(word_len) on average.

4) Prefix search : trie takes theta(word_len + output_len) and hashing does not support prefix search.

5) Lexicographic ordering : trie takes theta (number of words) and hashing does not support lexicographic ordering.