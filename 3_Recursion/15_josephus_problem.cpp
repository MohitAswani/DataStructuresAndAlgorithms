#include<bits/stdc++.h>
using namespace std;
/**
 * @brief In this problem there are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in a circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
 * 
 * We always know that in josephus(1,k) the person with 0th position IN THAT CIRCLE will be saved. So now all we have to do is to find what will his relative to josephus(n,k).
 * 
 * So when we see jos(2,k),jos(3,k) and so on we observe a pattern. The pattern is that the i th person in jos(n-1,k) is   (i+k)%n th person in jos(n,k).
 * 
 * So now we just need to find the value of the 0th person in jos(1,k) for jos(n,k) and we do that recursively.
 * 
 * Time complexity : O(n).
 * Auxillary space : O(n).
 * 
 * @param n 
 * @param k 
 * @return int 
 */
int josephus(int n,int k)
{
    if(n==1)
    {
        return 0;
    }

    return (josephus(n-1,k)+k)%n;
}
int main(){
    cout<<"PERSON LEFT :"<<josephus(3,3)<<endl;
    return 0;
}