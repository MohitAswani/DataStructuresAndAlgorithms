#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node
{
public:
    Node *next;
    ll val;
    Node(ll val)
    {
        this->val = val;
        next = NULL;
    }
};
/**
 * @brief To perform enqueue and dequeue in O(1) we will have to choose the head as front since its easy to remove the head since there is not previous.
 *
 * If we were to choose the tail as front the dequeue operation would have a time complexity of O(n).
 *
 * All the operations in the following queue can be performed in O(1).
 */
class QueueUsingLL
{
    Node *front, *rear;
    ll size;

public:
    QueueUsingLL()
    {
        front = NULL;
        rear = NULL;
        size=0;
    }

    void enqueue(ll data)
    {
        Node *temp = new Node(data);
        size++;

        if (front == NULL)  // list is empty
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if (front == NULL)   // list is empty
        {
            return;
        }
        else
        {
            size--;
            Node *temp = front;
            front = front->next;
            if (front == NULL)      // list has only one element
            {
                rear = NULL;
            }
            delete temp;
        }
    }
};
int main()
{
    return 0;
}