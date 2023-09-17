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

class Solution
{
public:
 ListNode *oddEvenList(ListNode *head)
 {
  if (head == NULL || head->next == NULL)
  {
   return head;
  }
  ListNode *oddHead = head,
           *evenHead = head->next,
           *temp = head->next->next,
           *odd = oddHead,
           *even = evenHead;
  int count = 2;
  while (temp != NULL)
  {
   count++;
   if (count % 2 != 0)
   {
    odd->next = temp;
    odd = temp;
   }
   else
   {
    even->next = temp;
    even = temp;
   }
   temp = temp->next;
  }
  odd->next = evenHead;
  even->next = NULL;
  return oddHead;
 }
};