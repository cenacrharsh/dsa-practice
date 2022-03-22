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

//# Tutorial: https://www.youtube.com/watch?v=wIB5sg_Ulx4

//! Simple Traversal

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 ListNode *deleteDuplicates(ListNode *head)
 {
  if (head == NULL)
  {
   return NULL;
  }
  ListNode *curr = head;
  while (curr != NULL && curr->next != NULL)
  {
   if (curr->val == curr->next->val)
   {
    curr->next = curr->next->next; //* skip the next node if it's value is = to curr node's val
   }
   else
   {
    curr = curr->next;
   }
  }
  return head;
 }
};

//! Using Unordered Map

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 ListNode *deleteDuplicates(ListNode *head)
 {
  if (head == NULL || head->next == NULL)
  {
   return head;
  }

  unordered_map<int, int> freq;
  ListNode *curr = head->next, *prev = head;
  freq[head->val] = 1;
  while (curr != NULL)
  {
   if (freq.find(curr->val) != freq.end())
   {
    prev->next = curr->next;
    curr = curr->next;
   }
   else
   {
    freq[curr->val] = 1;
    prev = curr;
    curr = curr->next;
   }
  }

  return head;
 }
};