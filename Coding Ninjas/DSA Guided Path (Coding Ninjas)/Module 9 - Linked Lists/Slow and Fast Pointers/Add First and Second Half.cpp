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
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the number of nodes in the linkedlist.
*/

// Function used to add two linked lists.
Node *addTwoLinkedList(Node *head1, Node *head2)
{
 Node *prev = NULL;
 int carry = 0;

 while (head1 != NULL || head2 != NULL)
 {
  int sum = carry + head1->data;
  if (head2 != NULL)
  {
   sum += head2->data;
  }

  if (sum > 9)
  {
   sum -= 10;
   carry = 1;
  }
  else
  {
   carry = 0;
  }

  head1->data = sum;
  Node *temp = head1->next;
  head1->next = prev;
  prev = head1;
  head1 = temp;

  if (head2 != NULL)
  {
   head2 = head2->next;
  }
 }

 if (carry == 1)
 {
  head1 = new Node(1);
  head1->next = prev;
 }
 else
 {
  head1 = prev;
 }

 return head1;
}

Node *addFirstAndSecondHalf(Node *head)
{
 if (head == NULL)
 {
  return NULL;
 }

 Node *prev = NULL;

 Node *slow = head, *fast = head;
 while (fast != NULL && fast->next != NULL)
 {
  fast = fast->next->next;

  Node *temp = slow->next;
  slow->next = prev;
  prev = slow;
  slow = temp;
 }

 if (fast != NULL)
 {
  Node *temp = slow->next;
  slow->next = prev;
  prev = slow;
  slow = temp;
 }

 // Now slow will point to the head for second list.
 Node *head1 = prev;
 prev = NULL;
 while (slow != NULL)
 {
  Node *temp = slow->next;
  slow->next = prev;
  prev = slow;
  slow = temp;
 }

 Node *sumHead = addTwoLinkedList(head1, prev);

 while (sumHead != NULL && sumHead->data == 0)
 {
  sumHead = sumHead->next;
 }

 // If all digits in the sum string are zero, return only "0".
 if (sumHead == NULL)
 {
  return new Node(0);
 }

 return sumHead;
}
