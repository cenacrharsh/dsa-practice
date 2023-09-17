#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
We have one input stack, onto which we push the incoming elements, and one output stack, from which we peek/pop. We move elements from input stack to output stack when needed, i.e., when we need to peek/pop but the output stack is empty. When that happens, we move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).
*/

/*
> Time Complexity: O(1) (amortized)
> Space Complexity: O()
*/

class MyQueue
{
public:
 stack<int> input, output;

 MyQueue()
 {
 }

 void push(int x)
 {
  input.push(x);
 }

 int pop()
 {
  int ele_at_top = peek();
  output.pop();
  return ele_at_top;
 }

 int peek()
 {
  if (output.empty())
  {
   while (!input.empty())
   {
    output.push(input.top());
    input.pop();
   }
  }
  return output.top();
 }

 bool empty()
 {
  return (input.empty() && output.empty());
 }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */