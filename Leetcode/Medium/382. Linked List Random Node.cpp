#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=qQDM1J02Sq4

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
 ListNode *head = NULL;

 Solution(ListNode *head)
 {
  this->head = head;
 }

 int getRandom()
 {
  int ans = 0, i = 1;
  ListNode *temp = head;
  while (temp != NULL)
  {
   if (rand() % i == 0)
   {
    ans = temp->val;
   }
   i++;
   temp = temp->next;
  }
  return ans;
 }
};
