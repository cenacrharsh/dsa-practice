#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
  int longestMonotonicSubarray(vector<int> &nums)
  {
    if (nums.size() == 1)
    {
      return 1;
    }
    int inc = 1, dec = 1, ans = 0;
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] > nums[i - 1])
      {
        inc++;
        dec = 1;
      }
      else if (nums[i] < nums[i - 1])
      {
        dec++;
        inc = 1;
      }
      else
      {
        inc = 1;
        dec = 1;
      }
      // ans = max(ans, max(inc, dec));
      ans = max({ans, inc, dec});
    }
    return ans;
  }
};