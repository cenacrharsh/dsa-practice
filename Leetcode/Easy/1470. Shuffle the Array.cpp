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
 vector<int> shuffle(vector<int> &nums, int n)
 {
  vector<int> ans(2 * n);
  for (int i = 0; i < n; i++)
  {
   ans[2 * i] = nums[i];
   ans[2 * i + 1] = nums[n + i];
  }
  return ans;
 }
};