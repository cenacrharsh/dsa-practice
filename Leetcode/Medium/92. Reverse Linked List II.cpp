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
 ListNode *reverseBetween(ListNode *head, int left, int right)
 {
  ListNode *prevNode = NULL, *currNode = head, *nextNode = NULL, *h = NULL, *t = NULL, *listHead = NULL, *listTail = NULL;
  int count = 0;
  while (currNode != NULL)
  {
   count++;
   nextNode = currNode->next;
   if (count == left)
   {
    if (prevNode != NULL)
    {
     listHead = prevNode;
    }
    t = currNode;
    while (count != right)
    {
     currNode->next = prevNode;

     prevNode = currNode;
     currNode = nextNode;
     nextNode = currNode->next;
     count++;
    }
    listTail = currNode->next;
    currNode->next = prevNode;
    h = currNode;

    if (listHead == NULL)
    {
     head = h;
    }
    else
    {
     listHead->next = h;
    }
    t->next = listTail;
    break;
   }
   prevNode = currNode;
   currNode = nextNode;
  }
  return head;
 }
};