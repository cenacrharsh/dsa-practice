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

//! Merge Sort
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
 ListNode *sortList(ListNode *head)
 {
  if (head == NULL || head->next == NULL)
  {
   return head;
  }

  ListNode *slow = head, *fast = head, *prev = NULL;
  while (fast != NULL && fast->next != NULL)
  {
   prev = slow;
   slow = slow->next;
   fast = fast->next->next;
  }
  prev->next = NULL;
  ListNode *list1Head = head;
  ListNode *list2Head = slow;

  list1Head = sortList(list1Head);
  list2Head = sortList(list2Head);

  head = mergeTwoLists(list1Head, list2Head);

  return head;
 }
};