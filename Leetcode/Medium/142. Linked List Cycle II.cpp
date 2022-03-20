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
 ListNode *detectCycle(ListNode *head)
 {
  if (head == NULL)
  {
   return NULL;
  }

  ListNode *slow = head, *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
   slow = slow->next;
   fast = fast->next->next;

   if (slow == fast)
   {
    break;
   }
  }

  if (fast == NULL || fast->next == NULL)
  {
   return NULL;
  }

  slow = head;
  while (slow != fast)
  {
   slow = slow->next;
   fast = fast->next;
  }

  return slow;
 }
};