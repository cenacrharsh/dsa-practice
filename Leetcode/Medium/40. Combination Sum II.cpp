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
 void helper(int index, vector<int> &ds, vector<vector<int>> &ans, vector<int> &candidates, int target)
 {
  if (target == 0)
  {
   ans.push_back(ds);
   return;
  }

  for (int i = index; i < candidates.size(); i++)
  {
   if (i > index && candidates[i] == candidates[i - 1])
   {
    continue;
   }

   if (candidates[i] > target)
   {
    break;
   }

   ds.push_back(candidates[i]);
   helper(i + 1, ds, ans, candidates, target - candidates[i]);
   ds.pop_back();
  }
 }

 vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
 {
  sort(candidates.begin(), candidates.end());
  vector<int> ds;
  vector<vector<int>> ans;
  helper(0, ds, ans, candidates, target);
  return ans;
 }
};