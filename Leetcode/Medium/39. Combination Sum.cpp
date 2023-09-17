#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Recursion

class Solution
{
public:
 void helper(int index, vector<int> &tempSum, vector<vector<int>> &ans, vector<int> &candidates, int target)
 {
  if (index == candidates.size())
  {
   if (target == 0)
   {
    ans.push_back(tempSum);
   }
   return;
  }

  // pick up the element
  if (candidates[index] <= target)
  {
   tempSum.push_back(candidates[index]);
   helper(index, tempSum, ans, candidates, target - candidates[index]);
   tempSum.pop_back();
  }
  helper(index + 1, tempSum, ans, candidates, target);
 }

 vector<vector<int>> combinationSum(vector<int> &candidates, int target)
 {
  vector<int> tempSum;
  vector<vector<int>> ans;
  helper(0, tempSum, ans, candidates, target);
  return ans;
 }
};