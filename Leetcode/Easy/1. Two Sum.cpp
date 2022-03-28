#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Unordered Map

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 vector<int> twoSum(vector<int> &nums, int target)
 {
  unordered_map<int, int> unique;
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
   int search = target - nums[i];
   if (unique.find(search) != unique.end())
   {
    ans.push_back(i);
    ans.push_back(unique[search]);
    break;
   }

   unique[nums[i]] = i;
  }
  return ans;
 }
};