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
 int maxScore(vector<int> &nums)
 {
  sort(nums.begin(), nums.end(), greater<int>());
  int ans = 0;
  vector<long long> prefix(nums.size(), 0);
  prefix[0] = nums[0];
  if (prefix[0] > 0)
  {
   ans++;
  }
  for (int i = 1; i < nums.size(); i++)
  {
   prefix[i] = prefix[i - 1] + nums[i];
   if (prefix[i] > 0)
    ans++;
  }
  return ans;
 }
};