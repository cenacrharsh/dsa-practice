#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 1 Queue

class MyStack
{
public:
 queue<int> q1;

 MyStack()
 {
 }

 void push(int x)
 {
  q1.push(x);
  for (int i = 0; i < q1.size() - 1; i++)
  {
   q1.push(q1.front());
   q1.pop();
  }
 }

 int pop()
 {
  int top_element = q1.front();
  q1.pop();
  return top_element;
 }

 int top()
 {
  return q1.front();
 }

 bool empty()
 {
  return q1.empty();
 }
};

//! Using 2 Queues

class MyStack
{
public:
 queue<int> q1, q2;

 MyStack()
 {
 }

 void push(int x)
 {
  q2.push(x);
  while (!q1.empty())
  {
   q2.push(q1.front());
   q1.pop();
  }
  swap(q1, q2);
 }

 int pop()
 {
  int top_element = q1.front();
  q1.pop();
  return top_element;
 }

 int top()
 {
  return q1.front();
 }

 bool empty()
 {
  return q1.empty();
 }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */