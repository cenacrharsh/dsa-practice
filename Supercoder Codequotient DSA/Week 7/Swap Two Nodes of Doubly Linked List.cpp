#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node
{
 int data;
 struct Node *next;
 struct Node *prev;
};

void swapNodes(struct Node **head, int x, int y)
{
 struct Node *first = NULL, *second = NULL;
 struct Node *curr = *head;

 while (curr)
 {
  if (curr->data == x || curr->data == y)
  {
   if (!first)
    first = curr;
   else
   {
    second = curr;
    break;
   }
  }
  curr = curr->next;
 }

 //* edge case - both nodes are next to each other

 // head/-> <-x-> <-     -> <-y-> <-/NULL
 if (first && second && (first != second))
 {
  // If first node is not the head node
  if (first->prev != NULL)
   first->prev->next = second;
  else
   *head = second;
  second->prev->next = first;

  // If second node is not the last node
  if (second->next != NULL)
   second->next->prev = first;
  first->next->prev = second;

  struct Node *temp;
  temp = first->next;
  first->next = second->next;
  second->next = temp;

  temp = first->prev;
  first->prev = second->prev;
  second->prev = temp;
 }
}