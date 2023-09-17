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
 ListNode *removeElements(ListNode *head, int val)
 {
  if (head == NULL)
  {
   return NULL;
  }
  ListNode *temp = head;
  while (temp->next != NULL)
  {
   if (temp->next->val == val)
   {
    ListNode *del = temp->next;
    temp->next = temp->next->next;
    del = NULL;
    delete del;
   }
   else
   {
    temp = temp->next;
   }
  }
  if (head->val == val)
  {
   ListNode *del = head;
   head = head->next;
   del = NULL;
   delete del;
  }
  return head;
 }
};