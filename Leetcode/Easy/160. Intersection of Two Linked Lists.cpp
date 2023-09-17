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
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
 ListNode *getIntersection(int d, ListNode *headA, ListNode *headB)
 {
  ListNode *temp1 = headA, *temp2 = headB;
  for (int i = 0; i < d; i++)
  {
   temp1 = temp1->next;
  }
  while (temp1 != NULL && temp2 != NULL)
  {
   if (temp1 == temp2)
   {
    return temp1;
   }
   temp1 = temp1->next;
   temp2 = temp2->next;
  }
  return NULL;
 }
 int getCount(ListNode *head)
 {
  ListNode *temp = head;
  int count = 0;
  while (temp != NULL)
  {
   count++;
   temp = temp->next;
  }
  return count;
 }
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
 {
  int c1 = getCount(headA);
  int c2 = getCount(headB);
  if (c1 > c2)
  {
   int d = c1 - c2;
   return getIntersection(d, headA, headB);
  }
  else
  {
   int d = c2 - c1;
   return getIntersection(d, headB, headA);
  }
 }
};