#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=Of0HPkk3JgI

struct ListNode
{
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
> Time Complexity: O(n/k * k) -> O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 ListNode *reverseKGroup(ListNode *head, int k)
 {
  if (head == NULL || k == 1)
  {
   return head;
  }

  ListNode *dummy = new ListNode(0);
  dummy->next = head; //! d->1->2->3->4

  ListNode *temp = head;
  int count = 0;
  while (temp != NULL)
  {
   count++;
   temp = temp->next;
  }

  ListNode *prevNode = dummy, *currNode = dummy, *nextNode = dummy;
  while (count >= k)
  {
   currNode = prevNode->next;
   nextNode = currNode->next; //* prev @ dummy, curr @ 1, next @ 2
   for (int i = 1; i < k; i++)
   {
    currNode->next = nextNode->next; //* 1->3, 1->4
    nextNode->next = prevNode->next; //* 2>1, 3->2
    prevNode->next = nextNode;       //* d->2, d->3
    nextNode = currNode->next;       //* next @ 3, next @ 4
   }
   //! d->3->2->1->4
   prevNode = currNode; //* curr @ 1 so prev @ 1
   count -= k;
  }
  return dummy->next;
 }
};