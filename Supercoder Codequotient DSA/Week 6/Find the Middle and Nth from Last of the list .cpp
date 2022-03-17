#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
 int data;
 Node *next;
};

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

void forwardPrint(struct Node *head)
{
 if (head == NULL)
  return;

 cout << head->data << " ";
 forwardPrint(head->next);
}

void insertEnd(Node **head, int data)
{
 Node *node = new Node();
 Node *last = *head;
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

/*
struct Node
{
    int data;
    Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only
*/

//! Approach 1

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

/* struct Node
{
    int data;
    Node* next;
};

Above structure is used to define the linked list, You have to complete the below functions only */

int findMiddle(Node *head)
{
 if (head == NULL)
 {
  return -1;
 }
 Node *slow = head;
 Node *fast = head;
 while (fast != NULL && fast->next != NULL)
 {
  slow = slow->next;
  fast = fast->next->next;
 }
 return slow->data;
}

int findNLast(Node *head, int n)
{
 if (head == NULL || n <= 0)
 {
  return -1;
 }
 Node *first = head;
 Node *prev = NULL; //* since n can be > nodes in LL
 Node *second = head;
 for (int i = 0; i < n; i++)
 {
  prev = second;
  second = second->next;
  if (second == NULL)
  {
   break;
  }
 }

 if (second == NULL)
 {
  return prev->data;
 }

 while (second != NULL)
 {
  first = first->next;
  second = second->next;
 }

 return first->data;
}

//! Approach 2

/*
> Time Complexity: O(2n)
> Space Complexity: O(1)
*/

int findMiddle(Node *head)
{
 // Write your code here
 if (head == NULL)
 {
  return -1;
 }

 Node *temp = head;
 int count = 0;
 while (temp != NULL)
 {
  count++;
  temp = temp->next;
 }

 if (count == 0)
 {
  return -1;
 }

 int mid = (count / 2) + 1;
 temp = head;
 count = 0;
 while (temp != NULL)
 {
  count++;
  if (count == mid)
  {
   return temp->data;
  }
  temp = temp->next;
 }
}

int findNLast(Node *head, int n)
{
 // Write your code here
 Node *temp = head;
 int count = 0;
 while (temp != NULL)
 {
  count++;
  temp = temp->next;
 }

 if (count == 0)
 {
  return -1;
 }

 int node;

 if (n > count)
 {
  node = count;
 }
 else
 {
  node = count - n + 1;
 }

 temp = head;
 count = 0;
 while (temp != NULL)
 {
  count++;
  if (count == node)
  {
   return temp->data;
  }
  temp = temp->next;
 }
}
