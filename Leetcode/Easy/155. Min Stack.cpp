#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 Stack

/*
> Efficient Solution:

* You need to make two separate stacks for solving the problem.

* The first stack would have the actual number and the second stack would contain the minimum number present in the current stack.

* There is a modification in this approach, that the second stack(for maintaining minimum elements) would only push an element if it is less than or equal to the element at its top. This would help us reduce the space complexity(although in the worst case it would remain the same).

* Now, when we need to push a number in the stack, we first need to check if the stack is empty or not. If the stack is empty, we simply push the integer in both the stacks. Otherwise, we push the integer in the first stack and take the minimum of the top of the second stack and the current number and push it in the second stack.

* For ‘POP’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, we first save the top of the first stack and pop it. Finally, we return it.

* For ‘TOP’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, we return the top of the first stack.

* For ‘GETMIN’, we need to check if the stack is empty. If the stack is empty, we return ‘-1’. Otherwise, we return the top of the second stack.

* For ‘ISEMPTY’, we just need to check if the stack is empty.
*/

/*
> Time Complexity: O(1) -> for all operations
> Space Complexity: O(1)
*/

class MinStack
{
public:
 stack<int> s1, s2;

 MinStack()
 {
 }

 void push(int val)
 {
  s1.push(val);
  if (s2.empty() || val <= s2.top())
  {
   s2.push(val);
  }
 }

 void pop()
 {
  if (s1.empty())
  {
   return;
  }
  if (s1.top() == s2.top())
  {
   s2.pop();
  }
  s1.pop();
 }

 int top()
 {
  if (s1.empty())
  {
   return -1;
  }
  return s1.top();
 }

 int getMin()
 {
  if (s1.empty())
  {
   return -1;
  }
  return s2.top();
 }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */