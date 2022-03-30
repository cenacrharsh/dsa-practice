#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Negative Array

class Solution
{
public:
 vector<int> findDuplicates(vector<int> &nums)
 {
  vector<int> ans;

  for (int i = 0; i < nums.size(); i++)
  {
   int index = abs(nums[i]) - 1;

   if (nums[index] < 0)
   {
    ans.push_back(index + 1); //* ans.push_back(abs(nums[index]))
   }
   else
   {
    nums[index] = -1 * nums[index];
   }
  }

  return ans;
 }
};