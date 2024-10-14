#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=e7XQLtOQM3I&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c

//! we push first element of nums2 into stack and start iterating from 2nd element, if we find any element i.e. greater than it than we store it in map and pop if off and store the next element in stack, but if not we still store the new element in stack as we have to find the next greater element so now our curr element is the new element in num2 and this way we keep iterating and soon as we find someone greater we map it and pop it, but we do it in a while loop because the curr element might be greater than those elements that are already in stack as well, if yes we map them and pop them if not we now push this new element and move ahead as before, in the end all elements who had a next greater element have been placed in map

/*
> Time Complexity: O(N + N)
> Space Complexity: O(N) + O(N)
*/

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    stack<int> st;
    unordered_map<int, int> mp;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= nums2[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        mp[nums2[i]] = -1;
      }
      else
      {
        mp[nums2[i]] = st.top();
      }
      st.push(nums2[i]);
    }

    vector<int> ans(nums1.size(), 0);
    for (int i = 0; i < nums1.size(); i++)
    {
      ans[i] = mp[nums1[i]];
    }
    return ans;
  }
};