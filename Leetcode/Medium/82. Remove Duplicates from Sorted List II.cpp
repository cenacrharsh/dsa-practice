#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=R6-PnHODewY

//! Approach 1: Sentinel Head + Predecessor

/*
> Sentinel Head

* Let's start from the most challenging situation: the list head is to be removed.

* The standard way to handle this use case is to use the so-called Sentinel Node. Sentinel nodes are widely used for trees and linked lists as pseudo-heads, pseudo-tails, etc. They are purely functional and usually don't hold any data. Their primary purpose is to standardize the situation to avoid edge case handling.

* For example, let's use here pseudo-head with zero value to ensure that the situation "delete the list head" could never happen, and all nodes to delete are "inside" the list.
*/

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

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
 ListNode *deleteDuplicates(ListNode *head)
 {
  // sentinel
  ListNode *sentinel = new ListNode(0, head);

  // predecessor = the last node, before the sublist of duplicates
  ListNode *pred = sentinel;

  while (head != NULL)
  {
   // if it's a beginning of duplicates sublist skip all duplicates
   if (head->next != NULL && head->val == head->next->val)
   {
    // move till the end of duplicates sublist
    while (head->next != NULL && head->val == head->next->val)
    {
     head = head->next;
    }
    // skip all duplicates
    pred->next = head->next;
    // otherwise, move predecessor
   }
   else
   {
    pred = pred->next;
   }

   // move forward
   head = head->next;
  }
  return sentinel->next;
 }
};