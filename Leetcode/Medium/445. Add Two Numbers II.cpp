#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=Yc9buffV1G0

struct ListNode
{
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
> Time Complexity: O(m+n)
> Space Complexity: O(max(m,n))
*/

class Solution
{
public:
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
 {
  stack<int> st1;
  stack<int> st2;

  ListNode *temp1 = l1, *temp2 = l2;

  while (temp1 != NULL)
  {
   st1.push(temp1->val);
   temp1 = temp1->next;
  }

  while (temp2 != NULL)
  {
   st2.push(temp2->val);
   temp2 = temp2->next;
  }

  ListNode *result = NULL;

  int carry = 0;
  while (!st1.empty() || !st2.empty() || carry != 0)
  {
   int sum = 0;
   if (!st1.empty())
   {
    sum += st1.top();
    st1.pop();
   }
   if (!st2.empty())
   {
    sum += st2.top();
    st2.pop();
   }

   sum += carry;
   carry = sum / 10;
   ListNode *newNode = new ListNode(sum % 10);

   if (result == NULL)
   {
    result = newNode;
   }
   else
   {
    newNode->next = result;
    result = newNode;
   }
  }
  return result;
 }
};