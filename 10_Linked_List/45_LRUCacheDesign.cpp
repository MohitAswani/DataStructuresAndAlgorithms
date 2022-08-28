#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

/*
 * Simple implementation : * Using array.
 *                         * Hit and miss both O(n)
 *
 * Efficient implementation : * We need quick insertion and removal operations for this data structure so we use hash table.
 *                            * To maitain the order of recency we used double linked list as hash table is unordered.
 *                            * Also doubly linked list allows us to move an item from the middle to the beginning.
 *                            * Also in our hash map we store the reference to the node of doubly linked list node.
 *                            * Time complexity : Hit : O(1), Miss : O(1)
 *
 */
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};
void traverse(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
class Cache
{
    ll size;
    unordered_map<ll, Node *> hash_table;
    Node *head;
    Node *tail;

public:
    Cache(ll size)
    {
        this->size = size;
        head = NULL;
        tail = NULL;
    }
    void Refer(ll x)
    {
        if (hash_table.find(x) != hash_table.end()) // Present in hash table
        {
            Node *node = hash_table[x];

            if (node->prev == NULL) // When it is the first element
            {
                return;
            }
            else if (node->next == NULL) // When it is the last element and not the first element.
            {
                Node *prev = node->prev;
                tail = prev;
                prev->next = NULL;

                node->next = head;
                node->prev = NULL;

                head->prev = node;

                head = node;
                return;
            }
            else // The node is in the middle.
            {
                Node *next = node->next;
                Node *prev = node->prev;

                next->prev = prev;
                prev->next = next;

                node->next = head;
                node->prev = NULL;

                head->prev = node;

                head = node;
                return;
            }
        }
        else
        {
            if (hash_table.size() == this->size) // When the size becomes more.
            {
                // Removing an element from the end.

                if (tail != NULL && tail->prev == NULL)
                {
                    hash_table.erase(tail->data);
                    Node *temp = tail;
                    tail = NULL;
                    head = NULL;
                    delete temp;
                }
                else if (tail != NULL)
                {
                    hash_table.erase(tail->data);
                    Node *temp = tail;
                    tail = tail->prev;
                    tail->next = NULL;
                    delete temp;
                }

                // Insertion at the beginning

                Node *node = new Node(x);
                hash_table[x] = node;

                if (head == NULL)
                {
                    head = node;
                    tail = node;
                    return;
                }

                node->next = head;
                head->prev = node;
                head = node;
            }
            else
            {
                // Simply insert at the beginning

                Node *node = new Node(x);
                hash_table[x] = node;

                if (head == NULL)
                {
                    head = node;
                    tail = node;
                    return;
                }

                node->next = head;
                head->prev = node;
                head = node;
            }
        }
    }
};

int main()
{
    int a;
    Cache *c1 = new Cache(4);
    c1->Refer(10);
    c1->Refer(20);
    c1->Refer(10);
    c1->Refer(30);
    c1->Refer(40);
    c1->Refer(50);
    c1->Refer(30);
    c1->Refer(40);
    c1->Refer(60);
    c1->Refer(30);

    return 0;
}