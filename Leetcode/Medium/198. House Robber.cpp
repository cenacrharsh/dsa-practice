#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 int rob(vector<int> &nums)
 {
  int n = nums.size();
  if (n == 1)
  {
   return nums[0];
  }
  vector<int> maxMoney(n, 0);
  maxMoney[0] = nums[0];
  maxMoney[1] = max(nums[0], nums[1]);
  for (int i = 2; i < n; i++)
  {
   maxMoney[i] = max(maxMoney[i - 1], nums[i] + maxMoney[i - 2]);
  }
  return maxMoney[n - 1];
 }
};