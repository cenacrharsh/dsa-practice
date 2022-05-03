#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Stack

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int findUnsortedSubarray(vector<int> &nums)
 {
  stack<int> st1, st2;
  int l = nums.size(), r = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   while (!st1.empty() && nums[i] < nums[st1.top()])
   {
    int top = st1.top();
    l = min(l, top);
    st1.pop();
   }
   st1.push(i);
  }

  for (int i = nums.size() - 1; i >= 0; i--)
  {
   while (!st2.empty() && nums[i] > nums[st2.top()])
   {
    int top = st2.top();
    r = max(r, top);
    st2.pop();
   }
   st2.push(i);
  }

  return (r - l > 0 ? (r - l + 1) : 0);
 }
};

//! Nested Loops

/*
> Time Complexity: O(n^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int findUnsortedSubarray(vector<int> &nums)
 {
  int l = nums.size(), r = 0;
  for (int i = 0; i < nums.size() - 1; i++)
  {
   for (int j = i + 1; j < nums.size(); j++)
   {
    if (nums[j] < nums[i])
    {
     l = min(l, i);
     r = max(r, j);
    }
   }
  }
  if ((r - l) < 0)
  {
   return 0;
  }
  else
  {
   return (r - l + 1);
  }
 }
};