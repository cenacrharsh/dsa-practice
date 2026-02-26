#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void forwardPrint(struct Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    forwardPrint(head->next);
}

void insertEnd(struct Node **head, int data)
{
    struct Node *node = new Node();
    struct Node *last = *head;
    node->data = data; //  Insert data in new node
    node->next = NULL; // link new node to NULL as it is last node
    if (*head == NULL) // if list is empty add in beginning.
    {
        *head = node;
        return;
    }
    while (last->next != NULL) // Find the last node
        last = last->next;
    last->next = node; // Add the node after the last node of list
    return;
}

/* struct Node
{
    int data;
    struct Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only
*/

//! Iterative
struct Node *reverseList(struct Node *head)
{
    // Write your code here
    struct Node *prevNode = NULL, *currNode = head, *nextNode = NULL;
    while (currNode != NULL)
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;
    return head;
}

//! Recursive

struct Node *reverseListRecursively(struct Node *prevNode, struct Node *currNode)
{
    if (currNode == NULL)
    {
        return prevNode;
    }
    struct Node *nextNode = NULL;
    nextNode = currNode->next;
    currNode->next = prevNode;
    return reverseListRecursively(currNode, nextNode);
}

struct Node *reverseList(struct Node *head)
{
    // Write your code here
    head = reverseListRecursively(NULL, head);
    return head;
}

int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        struct Node *head = NULL;
        struct Node *newHead;
        cin >> n;
        while (n--)
        {
            cin >> m;
            insertEnd(&head, m);
        }
        newHead = reverseList(head);
        forwardPrint(newHead);
        cout << endl;
    }
    return 0;
}