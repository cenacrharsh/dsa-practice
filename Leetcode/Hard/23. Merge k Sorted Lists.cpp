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
 ListNode *mergeKLists(vector<ListNode *> &lists)
 {
  if (lists.size() == 0)
   return NULL;

  ListNode *dummyNode = new ListNode(-1);
  ListNode *currNode = dummyNode;

  // min heap containing value and pointer to currNode of LL
  priority_queue<pair<int, ListNode *>,
                 vector<pair<int, ListNode *>>,
                 greater<pair<int, ListNode *>>>
      pq;

  // pushing first node and address of head of all LL in priority queue
  for (auto head : lists)
  {
   if (head != NULL)
   {
    pq.push({head->val, head});
   }
  }

  while (!pq.empty())
  {
   ListNode *minNode = pq.top().second;
   pq.pop();

   // add minNode to LL
   currNode->next = minNode;
   currNode = currNode->next;

   // add next node of curr LL in priority queue
   if (minNode->next != NULL)
   {
    pq.push({minNode->next->val, minNode->next});
   }
  }
  return dummyNode->next;
 }
};