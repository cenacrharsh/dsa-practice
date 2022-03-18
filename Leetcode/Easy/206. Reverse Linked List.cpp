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
 ListNode *reverseList(ListNode *head)
 {
  if (head == NULL)
  {
   return NULL;
  }
  ListNode *prevNode = NULL, *currNode = head, *nextNode = NULL;
  while (currNode != NULL)
  {
   nextNode = currNode->next;
   currNode->next = prevNode;
   prevNode = currNode;
   currNode = nextNode;
  }
  head = prevNode;
  return head;
 }
};