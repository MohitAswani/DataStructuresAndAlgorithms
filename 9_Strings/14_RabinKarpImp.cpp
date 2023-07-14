#include <bits/stdc++.h>
#define ll long long
#define d 256 //this defines the total numbers we can consider
using namespace std;

const int q=101;

/**
 * @brief In rabin-karp algorithmn instead of comparing the characters directly we calculate the hash value of every window of the text and if it matches the hash value of pattern we compare the pattern with that window.
 * 
 * We do modulo as weighted sum might become very large . 
 * 
 * q is generally a prime no. and is a big as possible so that we have less spurious hits.
 * 
 * Here M=length of pattern, and N=length of text.
 * 
 * Time complextiy : O((N-M+1)*M) (Worst case in case of AAAAA and AAA) (Works better than naive at average)
 * 
 * RABIN KARP USED TO FIND MULTIPLE PATTERNS IN A TEXT SO IN THAT CASE WE USE AN ARRAY OF PATTERN HASHES AND COMPARE THEM.
 * 
 * @param text 
 * @param patt 
 */
void func(string &text, string &patt)
{  
    //Computing (d^(M-1))%q
    int h=1;
    for(int i=1;i<=patt.length()-1;i++)
    {
        h=(h*d)%q;
    }

    //Computing the hash values for text and pattern
    int p=0,t=0;
    for(int i=0;i<patt.length();i++)
    {
        p=(p*d+patt[i])%q;
        t=(t*d+text[i])%q;
    }
    
    for(int i=0;i<=(text.length()-patt.length());i++)
    {
        //Check for hit
        if(p==t)
        {
            bool cond=1;
            for(int j=0;j<patt.length();j++)
            {
                if(text[i+j]!=patt[j])
                {
                    cond=0;
                    break;
                }
            }
            if(cond==1)
            cout<<i<<" ";
        }
        //Computing t(i+1) using t(i)
        if(i<text.length()-patt.length())
        {
            t=(d*(t-h*text[i])+text[i+patt.length()])%q;
        }
        if(t<0)
        {
            t=t+q;
        }
    }

}
int main()
{
    string text = "ABCABCD";
    string patt = "ABCD";
    func(text, patt);
    //cout<<func(str)<<endl;
    return 0;
}