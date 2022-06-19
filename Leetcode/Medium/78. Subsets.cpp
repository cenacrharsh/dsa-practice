#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Bit Manipulation

class Solution
{
public:
 vector<vector<int>> subsets(vector<int> &nums)
 {
  int n = nums.size();
  vector<vector<int>> ans;
  for (int num = 0; num < (1 << n); num++)
  {
   vector<int> subset;
   for (int i = 0; i < n; i++)
   {
    if ((num & (1 << i)) != 0)
    {
     subset.push_back(nums[i]);
    }
   }
   ans.push_back(subset);
  }
  return ans;
 }
};

//! Using Backtracking

class Solution
{
public:
 vector<vector<int>> helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> subSet, int index, int n)
 {
  if (index == n)
  {
   ans.push_back(subSet);
   return ans;
  }

  //> pick the particular index into the subsequence
  subSet.push_back(nums[index]);
  helper(nums, ans, subSet, index + 1, n);

  //> not pick the particular index into the subsequence
  subSet.pop_back();
  helper(nums, ans, subSet, index + 1, n);

  return ans;
 }

 vector<vector<int>> subsets(vector<int> &nums)
 {
  vector<vector<int>> ans;
  vector<int> subSet;
  return helper(nums, ans, subSet, 0, nums.size());
 }
};