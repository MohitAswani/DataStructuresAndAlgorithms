#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

class Node
{

public:
    ll data;
    Node *next;

    Node(ll x)
    {
        data = x;
        next = NULL;
    }
};
class myStack
{

    Node *head;
    ll size;

public:
    myStack()
    {
        head = NULL;
        size = 0;
    }
    void push(ll x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }

    ll pop()
    {
        if (head == NULL)
        {
            return INT_MIN;
        }

        Node *temp = head;
        ll data = temp->data;
        head = head->next;
        size--;
        delete temp;
        return data;
    }

    ll peek()
    {
        if (head == NULL)
        {
            return INT_MIN;
        }

        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    ll stackSize()
    {
        return size;
    }

    ~myStack()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};
int main()
{
    myStack s;

    cout << s.pop() << endl;
    cout << s.peek() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.peek() << endl;
    cout << s.stackSize() << endl;
    cout << s.isEmpty() << endl;

    return 0;
}