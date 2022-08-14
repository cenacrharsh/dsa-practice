#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n! * n)
> Space Complexity: O(n) + O(n)
*/

class Solution
{
public:
 void helper(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int freq[])
 {
  if (ds.size() == nums.size())
  {
   ans.push_back(ds);
   return;
  }

  for (int i = 0; i < nums.size(); i++)
  {
   if (!freq[i])
   {
    ds.push_back(nums[i]);
    freq[i] = 1;

    helper(nums, ds, ans, freq);

    ds.pop_back();
    freq[i] = 0;
   }
  }
 }

 vector<vector<int>> permute(vector<int> &nums)
 {
  vector<vector<int>> ans;
  vector<int> ds;
  int freq[nums.size()];
  for (int i = 0; i < nums.size(); i++)
  {
   freq[i] = 0;
  }
  helper(nums, ds, ans, freq);
  return ans;
 }
};