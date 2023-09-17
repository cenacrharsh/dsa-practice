#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct ListNode
{
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// # Tutorial: https://www.youtube.com/watch?v=Xb4slcp1U38, https://www.youtube.com/watch?v=KVf1Uuqfv8E

//! Optimized Code - Iterative

/*
> Time Complexity: O(n + m)
> Space Complexity: O(1)
*/

class Solution
{
public:
 ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
 {
  if (list1 == NULL)
  {
   return list2;
  }
  if (list2 == NULL)
  {
   return list1;
  }

  if (list1->val > list2->val)
  {
   std::swap(list1, list2);
  }

  ListNode *result = list1;

  while (list1 != NULL && list2 != NULL)
  {
   ListNode *temp = NULL;
   while (list1 != NULL && list1->val <= list2->val)
   {
    temp = list1;
    list1 = list1->next;
   }
   temp->next = list2;
   std::swap(list1, list2);
  }
  return result;
 }
};

//! Exchanging Links Only
//* Better Time Complexity
class Solution
{
public:
 ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
 {
  if (list1 == NULL)
   return list2;
  if (list2 == NULL)
   return list1;

  ListNode *dummyNode = new ListNode(-1);
  ListNode *currNode = dummyNode;

  while (list1 != NULL && list2 != NULL)
  {
   if (list1->val < list2->val)
   {
    currNode->next = list1;
    list1 = list1->next;
   }
   else
   {
    currNode->next = list2;
    list2 = list2->next;
   }
   currNode = currNode->next;
  }

  while (list1 != NULL)
  {
   currNode->next = list1;
   list1 = list1->next;
   currNode = currNode->next;
  }

  while (list2 != NULL)
  {
   currNode->next = list2;
   list2 = list2->next;
   currNode = currNode->next;
  }

  return dummyNode->next;
 }
};
//* Better Space Complexity
class Solution
{
public:
 ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
 {
  if (list1 == NULL)
  {
   return list2;
  }
  if (list2 == NULL)
  {
   return list1;
  }

  ListNode *dummy = new ListNode(-1);

  if (list1->val <= list2->val)
  {
   dummy->next = list1;
   list1 = list1->next;
  }
  else
  {
   dummy->next = list2;
   list2 = list2->next;
  }

  ListNode *curr = dummy->next;

  while (list1 != NULL && list2 != NULL)
  {
   if (list1->val <= list2->val)
   {
    curr->next = list1;
    curr = curr->next;
    list1 = list1->next;
   }
   else
   {
    curr->next = list2;
    curr = curr->next;
    list2 = list2->next;
   }
  }
  while (list1 != NULL)
  {
   curr->next = list1;
   curr = curr->next;
   list1 = list1->next;
  }
  while (list2 != NULL)
  {
   curr->next = list2;
   curr = curr->next;
   list2 = list2->next;
  }
  return dummy->next;
 }
};

//! Personal Sol
class Solution
{
public:
 ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
 {
  if (list1 == NULL && list2 == NULL)
  {
   return NULL;
  }

  ListNode *temp1 = list1, *temp2 = list2, *prevNode = NULL, *head = NULL;

  if (list1 == NULL)
  {
   head = list2;
   return head;
  }
  else if (list2 == NULL)
  {
   head = list1;
   return head;
  }

  if (temp1->val <= temp2->val)
  {
   head = temp1;
   prevNode = temp1;
   temp1 = temp1->next;
  }
  else
  {
   head = temp2;
   prevNode = temp2;
   temp2 = temp2->next;
  }

  while (temp1 != NULL && temp2 != NULL)
  {
   if (temp1->val <= temp2->val)
   {
    prevNode->next = temp1;
    prevNode = temp1;
    temp1 = temp1->next;
   }
   else
   {
    prevNode->next = temp2;
    prevNode = temp2;
    temp2 = temp2->next;
   }
  }

  while (temp1 != NULL)
  {
   prevNode->next = temp1;
   prevNode = temp1;
   temp1 = temp1->next;
  }

  while (temp2 != NULL)
  {
   prevNode->next = temp2;
   prevNode = temp2;
   temp2 = temp2->next;
  }
  prevNode->next = NULL;

  return head;
 }
};