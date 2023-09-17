#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
    Time complexity: O(1)
        For push(): O(1) - Constant extra space is required.
        For pop(): O(1) - Constant extra space is required.
        For top(): O(1) - Constant extra space is required.
        For getMin(): O(1) - Constant extra space is required.
        For isEmpty(): O(1) - Constant extra space is required.

    Space complexity: O(1)
*/

#include <stack>

class SpecialStack
{
 stack<int> s1, s2;

public:
 void push(int data)
 {
  if (s2.empty() || data <= s2.top())
  {
   s2.push(data);
  }
  s1.push(data);
 }

 int pop()
 {
  if (isEmpty())
  {
   return -1;
  }
  if (s1.top() == s2.top())
  {
   s2.pop();
  }
  int x = s1.top();
  s1.pop();
  return x;
 }

 int top()
 {
  if (isEmpty())
  {
   return -1;
  }
  return s1.top();
 }

 bool isEmpty()
 {
  return s1.empty();
 }

 int getMin()
 {
  if (isEmpty())
  {
   return -1;
  }
  return s2.top();
 }
};