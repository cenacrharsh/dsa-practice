#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (oneHead->next != NULL) ? oneHead->next : twoHead->next; //* even if 1 is absent it'll point to 2 and if even 2 is absent it'll point to NULL which is fine
    one->next = twoHead->next;
    two->next = NULL;
    return zeroHead->next; //* if zero itself is absent it'll either point to oneHead->next or twoHead->next
}