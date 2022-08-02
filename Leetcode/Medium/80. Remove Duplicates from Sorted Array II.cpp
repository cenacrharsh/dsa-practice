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
 int removeDuplicates(vector<int> &nums)
 {
  if (nums.size() < 2)
  {
   return nums.size();
  }

  int k = 2;
  for (int i = 2; i < nums.size(); i++)
  {
   if (nums[i] == nums[k - 1])
   {
    if (nums[i] == nums[k - 2])
    {
     continue;
    }
    else
    {
     nums[k++] = nums[i];
    }
   }
   else
   {
    nums[k++] = nums[i];
   }
  }
  return k;
 }
};