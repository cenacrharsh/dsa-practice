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
 struct Node *next;
};

int isCircular(Node *head)
{
 // Write your code here
 if (head == NULL)
 {
  return 1;
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
  return 0;
 }
 if (slow == head)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}