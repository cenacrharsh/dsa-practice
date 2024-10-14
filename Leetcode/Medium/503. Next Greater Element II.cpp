#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=7PrncD7v9YQ&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=6

/*
> Time Complexity: O(2N + 2N)
> Space Complexity: O(2N) + O(2N)
*/

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    //* we don't actually double the array just deal with hypothetical indices
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, 0);
    for (int i = (2 * n) - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= nums[i % n])
      {
        st.pop();
      }
      if (i < n)
      {
        ans[i] = st.empty() ? -1 : st.top();
      }
      st.push(nums[i % n]);
    }
    return ans;
  }
};