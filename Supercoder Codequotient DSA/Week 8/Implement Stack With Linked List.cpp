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

class Stack
{
 // Write your code here
public:
 Node *head;
 int size;

 Stack()
 {
  // Write your code here
  head = NULL;
  size = 0;
 }

 int getSize()
 {
  // Write your code here
  return size;
 }

 bool isEmpty()
 {
  // Write your code here
  return (size == 0);
 }

 void push(int data)
 {
  // Write your code here
  Node *newNode = new Node(data);
  newNode->next = head;
  head = newNode;
  size++;
 }

 void pop()
 {
  // Write your code here
  if (size == 0)
  {
   return;
  }
  head = head->next;
  size--;
 }

 int getTop()
 {
  // Write your code here
  if (size == 0)
  {
   return -1;
  }
  return head->data;
 }
};