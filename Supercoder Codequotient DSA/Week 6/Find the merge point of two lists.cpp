#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n + m)
> Space Complexity: O(1)
*/

struct Node
{
 int data;
 Node *next;
};

Node *getIntersection(int d, Node *headA, Node *headB)
{
 Node *temp1 = headA, *temp2 = headB;
 for (int i = 0; i < d; i++)
 {
  temp1 = temp1->next;
 }
 while (temp1 != NULL && temp2 != NULL)
 {
  if (temp1 == temp2)
  {
   return temp1;
  }
  temp1 = temp1->next;
  temp2 = temp2->next;
 }
 return NULL;
}
int getCount(Node *head)
{
 Node *temp = head;
 int count = 0;
 while (temp != NULL)
 {
  count++;
  temp = temp->next;
 }
 return count;
}
Node *findMergePoint(Node *head1, Node *head2)
{
 int c1 = getCount(head1);
 int c2 = getCount(head2);
 if (c1 > c2)
 {
  int d = c1 - c2;
  return getIntersection(d, head1, head2);
 }
 else
 {
  int d = c2 - c1;
  return getIntersection(d, head2, head1);
 }
}