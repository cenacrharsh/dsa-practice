#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(max(n,m))
> Space Complexity: O(max(n+m))
*/

struct ListNode
{
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//# Tutorial: https://www.youtube.com/watch?v=LBVsXSMOIk4

class Solution
{
public:
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
 {
  ListNode *dummy = new ListNode();
  ListNode *temp = dummy;
  int carry = 0;
  while (l1 != NULL || l2 != NULL || carry != 0)
  {
   int sum = 0;
   if (l1 != NULL)
   {
    sum += l1->val;
    l1 = l1->next;
   }
   if (l2 != NULL)
   {
    sum += l2->val;
    l2 = l2->next;
   }

   sum += carry;
   carry = sum / 10;
   ListNode *newNode = new ListNode(sum % 10);
   temp->next = newNode;
   temp = temp->next;
  }
  return dummy->next;
 }
};