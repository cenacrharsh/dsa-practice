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
 ListNode *swapNodes(ListNode *head, int k)
 {
  ListNode *first = head;
  ListNode *last = head;
  ListNode *temp = head;
  int count = 1;
  while (count < k)
  {
   first = first->next;
   temp = temp->next;
   count++;
  }
  while (temp->next != NULL)
  {
   last = last->next;
   temp = temp->next;
  }
  int tempVal = first->val;
  first->val = last->val;
  last->val = tempVal;
  return head;
 }
};