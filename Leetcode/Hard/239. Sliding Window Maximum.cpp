#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N) + O(N) => Traversal + N pop_back (max we can push N elements inside queue hence max N pops)
> Space Complexity: O(K) + P(N - K) => At any time max elements stored in deque is K, (N-K) required to store the ans
*/

//* We'll maintain a Monotonic Stack => use Deque for this, Keep adding elements from back and pop from front of queue
class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    vector<int> ans;
    deque<int> dq; // stores indexes
    for (int i = 0; i < nums.size(); i++)
    {
      //* Remove the oldest element from deque when size exceeds window length
      if (!dq.empty() && dq.front() <= (i - k))
      {
        dq.pop_front();
      }

      //* Remove elements from back of deque if current element is > elements in queue, remove elements if == current element as well as we don't need to store equal elements
      while (!dq.empty() && nums[dq.back()] <= nums[i])
      {
        dq.pop_back();
      }

      dq.push_back(i);

      //* Valid window length starts when i reaches (k - 1)th index
      if (i >= k - 1)
      {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};