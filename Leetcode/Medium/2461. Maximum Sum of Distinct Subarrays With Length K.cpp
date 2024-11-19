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
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    if (nums.size() == 1 && k == 1)
    {
      return nums[0];
    }
    long long ans = 0;
    long long tempSum = 0;
    unordered_map<int, int> mp;
    int l = 0, r = 0;
    while (r < nums.size())
    {
      mp[nums[r]]++;
      tempSum += nums[r];
      if ((r - l + 1) == k)
      {
        if (mp.size() == k)
        {
          ans = max(ans, tempSum);
        }
        tempSum -= nums[l];
        mp[nums[l]]--;
        if (mp[nums[l]] == 0)
        {
          mp.erase(nums[l]);
        }
        l++;
        r++;
      }
      else
      {
        r++;
      }
    }
    return ans;
  }
};