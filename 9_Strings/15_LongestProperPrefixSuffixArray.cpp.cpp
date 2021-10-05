/*
Proper prefix of "abc":
"","a","ab" (cannot be "abc" since its 'proper')

Suffix of "abc":
"","c","bc","abc"

Proper prefix of "abcd":
"","a","ab","abc" (cannot be "abc" since its 'proper')

Suffix of "abcd":
"","d","cd","bcd","abcd"

Now we need to find the LPS(longest prefix suffix array) for string:

Eg:

str="ababc"

lps[]={0,0,1,2,0}

str="abacabad"

lps={0,0,1,0,1,2,3,0}

str="abbabb"

lps={0,0,0,1,2,3}
*/