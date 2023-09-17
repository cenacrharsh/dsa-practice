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
 void reverse(ListNode *&head)
 {
  ListNode *prev = NULL, *curr = head, *nextNode = NULL;
  while (curr != NULL)
  {
   nextNode = curr->next;
   curr->next = prev;
   prev = curr;
   curr = nextNode;
  }
  head = prev;
 }
 ListNode *findMiddle(ListNode *head, bool &odd)
 {
  ListNode *slow = head, *fast = head, *prev = NULL;
  while (fast != NULL && fast->next != NULL)
  {
   prev = slow;
   slow = slow->next;
   fast = fast->next->next;
  }

  if (fast != NULL)
  {
   odd = true;
  }

  prev->next = NULL;
  return slow;
 }
 bool compare(ListNode *head1, ListNode *head2)
 {
  ListNode *temp1 = head1;
  ListNode *temp2 = head2;

  while (temp1 != NULL && temp2 != NULL)
  {
   if (temp1->val == temp2->val)
   {
    temp1 = temp1->next;
    temp2 = temp2->next;
   }
   else
   {
    return false;
   }
  }
  if (temp1 == NULL && temp2 == NULL)
  {
   return true;
  }
  return false;
 }
 bool isPalindrome(ListNode *head)
 {
  if (head == NULL)
  {
   return false;
  }
  if (head->next == NULL)
  {
   return true;
  }
  bool odd = false;
  ListNode *mid = findMiddle(head, odd);
  if (odd)
  {
   mid = mid->next;
  }
  reverse(mid);
  bool ans = compare(head, mid);
  reverse(mid);
  return ans;
 }
};