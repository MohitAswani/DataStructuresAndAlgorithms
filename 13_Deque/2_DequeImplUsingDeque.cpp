#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
/**
 * @brief In the efficient implementation of deque using array we treat the array as a circular array and accordingly perform the requirred operations.
 * 
 * When we delete at front we do front=(front+1)%cap and when we do insert at rear we do rear=(rear+1)%cap.
 * 
 * When we insert at front we do0 front=(front-1+cap)%cap and when we do delete at rear we do rear=(rear-1+cap)%cap;
 * 
 * Also we do not have a variable for the rear element since we can simply find rear using rear = (front+size-1)%cap.
 */
class DequeUsingArray
{
    int *arr;
    int front,cap,size;
    
    public:
    DequeUsingArray(int cap)
    {
        this->cap=cap;
        size=0;
        front=0;
    }

    void insertFront(int x)
    {
        if(isFull())
        return ;

        front=(front-1+cap)%cap;
        arr[front]=x;
        size++;
    }

    void insertRear(int x)
    {
        if(isFull())
        return ;

        int rear=getRear();
        rear=(rear+1)%cap;
        arr[cap]=x;
        size++;
    }

    void deleteFront()
    {
        if(isEmpty())
        return;

        front=(front+1)%cap;
        size--;
    }

    void deleteRear()
    {
        if(isEmpty())
        return;

        // Since we are not maitain the rear variable hence we simply decrease the size.
        
        size--;
    }

    int getFront()
    {
        if(isEmpty())
        return -1;

        return front;
    }

    int getRear()
    {
        if(isEmpty())
        return -1;

        return (front+size-1)%cap;
    }

    bool isFull()
    {
        return size==cap;
    }

    bool isEmpty()
    {
        return size==0;
    }

    int getSize()
    {

    }

};
int main()
{
    return 0;
}