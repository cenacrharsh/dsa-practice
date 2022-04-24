#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution

class Solution
{
public:
 vector<int> intersection(vector<vector<int>> &nums)
 {
  int size = nums.size();
  map<int, int> num;
  for (auto i : nums)
  {
   for (int j : i)
   {
    num[j]++;
   }
  }
  vector<int> ans;
  for (auto i : num)
  {
   if (i.second == size)
   {
    ans.push_back(i.first);
   }
  }
  return ans;
 }
};