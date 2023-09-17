#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=ARkl69eBzhY&t=49s

// array contains duplicates and same numbers may have different next greater elements, therefore we don't use hashmap, and use stack to store indices
class Solution
{
public:
 vector<int> nextGreaterElements(vector<int> &nums)
 {
  int n = nums.size();
  vector<int> ans(n, -1);
  stack<int> st;
  //* to mimic the effect or circular array, we assume copy of arr is attached next to it
  for (int i = 0; i < 2 * n; i++)
  {
   while (!st.empty() && nums[i % n] > nums[st.top()])
   {
    ans[st.top()] = nums[i % n];
    st.pop();
   }

   if (i < n)
   {
    st.push(i);
   }
  }
  return ans;
 }
};