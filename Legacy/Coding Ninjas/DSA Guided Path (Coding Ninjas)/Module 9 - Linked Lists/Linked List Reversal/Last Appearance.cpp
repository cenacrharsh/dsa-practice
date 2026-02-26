#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Node
{
public:
 int data;
 Node *next;
 Node(int data)
 {
  this->data = data;
  this->next = NULL;
 }
};

Node *reverseList(Node *head)
{
 Node *prevNode = NULL, *currNode = head, *nextNode = NULL;
 while (currNode != NULL)
 {
  nextNode = currNode->next;
  currNode->next = prevNode;
  prevNode = currNode;
  currNode = nextNode;
 }
 return prevNode;
}
Node *lastAppearance(Node *head)
{
 // Write your code here.
 Node *dummy = new Node(-1);
 dummy->next = head;

 dummy->next = reverseList(dummy->next);

 unordered_map<int, int> visited;

 Node *temp = dummy->next, *prev = dummy;
 while (temp != NULL)
 {
  if (visited.find(temp->data) != visited.end())
  {
   prev->next = temp->next;
   temp = temp->next;
  }
  else
  {
   visited[temp->data] = 1;
   prev = temp;
   temp = temp->next;
  }
 }

 dummy->next = reverseList(dummy->next);

 return dummy->next;
}