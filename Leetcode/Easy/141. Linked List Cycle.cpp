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
 bool hasCycle(ListNode *head)
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
    return true;
   }
  }
  return false;
 }
};