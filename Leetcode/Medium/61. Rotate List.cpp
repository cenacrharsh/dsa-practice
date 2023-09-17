#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Approach

/*
> Time Complexity: O(n) + O(n - (n % k))
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
 ListNode *rotateRight(ListNode *head, int k)
 {
  if (head == NULL || head->next == NULL || k < 1)
  {
   return head;
  }
  ListNode *curr = head;
  int count = 1;
  while (curr->next != NULL)
  {
   count++;
   curr = curr->next;
  }
  // last node points to head
  curr->next = head;

  // calc value of effective k from start of LL, which will become the last node of rotated LL and k+1 th node will become the new head of LL
  k = count - k % count;

  // traverse and reach kth node, i.e. k - 1 traversals from head
  curr = head;
  for (int i = 1; i < k; i++)
  {
   curr = curr->next;
  }

  // now update head to point to k+1 th node, and kth node points to null
  head = curr->next;
  curr->next = NULL;

  return head;
 }
};

//! Brute Force - K rotations

/*
> Time Complexity: O(k * n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 ListNode *rotateRight(ListNode *head, int k)
 {
  if (head == NULL || head->next == NULL || k < 1)
  {
   return head;
  }

  for (int i = 0; i < k; i++)
  {
   ListNode *lastNode = head;
   ListNode *secondLastNode = NULL;
   while (lastNode->next != NULL)
   {
    secondLastNode = lastNode;
    lastNode = lastNode->next;
   }
   lastNode->next = head;
   secondLastNode->next = NULL;
   head = lastNode;
  }
  return head;
 }
};