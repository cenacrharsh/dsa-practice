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
 Node(int data)
 {
  this->data = data;
  this->next = NULL;
 }
};

/*
First, create an empty dummy linked list, which will store the final sorted array. (let this be called ‘sorted’).

Create a pointer ‘current’ which will be used to iterate over the given SLL. Initially, ‘current’ points to the head of the linked list.

Now we will select the elements of the linked list one by one using a while loop and store them at their correct position in the sorted list.

As we will be modifying the next pointer of the current node, it is better to store the original next pointer in a temporary variable, so that it is not lost and we can carry out the next iterations.

To place a node at its correct position in the sorted list, we use a function called “sortedInsert” which takes the head of the sorted list and the new node to be inserted as parameters.

In the “sortedInsert” function, we again make use of pointers to keep track of the position where the element should be inserted and then modify the original links to accommodate the new node.

Finally, return the sorted list and terminate.
*/

/*
 Time Complexity : O(N^2)
 Space Complexity : O(1)

 where 'N' is the number of nodes in the list
*/

// Function to insert an element at its correct position in sorted order.
void sortedInsert(Node **head, Node *newnode)
{

 Node *current;

 if (*head == NULL || ((*head)->data >= newnode->data))
 {
  newnode->next = *head;
  *head = newnode;
 }

 else
 {
  current = *head;
  while (current->next and current->next->data < newnode->data)
  {
   current = current->next;
  }
  newnode->next = current->next;
  current->next = newnode;
 }
}

Node *insertionSortLL(Node *head)
{

 // To store the final sorted list
 Node *sorted = NULL;

 // Current pointer, to iterate over the entire list
 Node *current = head;

 /*
This loops takes each element in the loop and calls sortedInsert function for it,
to insert it at its correct position in the final list
*/

 while (current)
 {
  Node *next = current->next;
  sortedInsert(&sorted, current);
  current = next;
 }

 return sorted;
}