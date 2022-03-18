#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

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
 ListNode *swapPairs(ListNode *head)
 {
  if (head == NULL)
  {
   return head;
  }

  ListNode *temp = new ListNode();
  temp->next = head;
  ListNode *current = temp;

  /*
   ! 1 -> 2 -> 3 -> 4 =>
   ! 2 -> 1 -> 3 -> 4 =>
   ! 2 -> 1 -> 4 -> 3
  */

  while (current->next != NULL && current->next->next != NULL)
  {
   ListNode *first = current->next;
   ListNode *second = current->next->next;

   first->next = second->next;  //* 1 -> 3, 3 -> NULL
   current->next = second;      //* head -> 2, 1 -> 4
   current->next->next = first; //* 2 -> 1, 4 -> 3

   current = current->next->next; //* head -> 1
  }
  return temp->next;
 }
};