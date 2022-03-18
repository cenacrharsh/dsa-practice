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
 ListNode *removeNthFromEnd(ListNode *head, int n)
 {
  if (head == NULL || head->next == NULL)
  {
   return NULL;
  }

  ListNode *first = head, *second = head, *prev = NULL;
  for (int i = 0; i < n; i++)
  {
   second = second->next;
  }

  while (second != NULL)
  {
   prev = first;
   first = first->next;
   second = second->next;
  }

  if (prev == NULL)
  {
   head = first->next;
  }
  else
  {
   prev->next = first->next;
  }

  return head;
 }
};