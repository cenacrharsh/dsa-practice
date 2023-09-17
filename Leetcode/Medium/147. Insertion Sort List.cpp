#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=CPAWcc78IB4

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

struct ListNode
{
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
 ListNode *insertionSortList(ListNode *head)
 {
  if (head == NULL || head->next == NULL)
  {
   return head;
  }
  ListNode *dummy = new ListNode(-1);
  dummy->next = head;

  ListNode *prev = dummy, *curr = dummy->next;
  while (curr != NULL)
  {
   if (curr->next && (curr->next->val < curr->val))
   {
    //! finding correct position
    while (prev->next && (prev->next->val < curr->next->val))
    {
     prev = prev->next;
    }
    //! rearranging pointers
    ListNode *temp = prev->next;
    prev->next = curr->next; //* next to prev is the correct pos for node at curr->next, hence we make the connection, and temp already stores the original node at that pos to avoid loosing it

    curr->next = curr->next->next; //* since node at curr->next is to be removed, curr->next skips it and points to node ahead of it

    prev->next->next = temp; //* prev->next now contains our newly inserted node, which now must point to the node we save in temp, that is the node earlier pointed to by prev, now since our newly inserted node sits in b/w them it should point to that node

    prev = dummy; //* resetting prev
   }
   else
   {
    curr = curr->next;
   }
  }
  return dummy->next;
 }
};