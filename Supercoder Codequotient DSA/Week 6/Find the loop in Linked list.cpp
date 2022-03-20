#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

struct Node
{
 int data;
 Node *next;
};

int loopInList(Node *head)
{
 // Write your code here
 if (head == NULL)
 {
  return NULL;
 }

 Node *slow = head, *fast = head;
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

 //* now we know loop exits, so we find the start of loop in LL
 slow = head;
 while (slow != fast)
 {
  slow = slow->next;
  fast = fast->next;
 }

//* now we have to find the no. of nodes in the loop
 int count = 1;
 Node *startOfLoopNode = slow;
 startOfLoopNode = startOfLoopNode->next;
 while (startOfLoopNode != slow)
 {
  count++;
  startOfLoopNode = startOfLoopNode->next;
 }

 return count;
}