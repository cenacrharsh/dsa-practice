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
  if (nums.size() <= 1)
  {
   return nums.size();
  }
  int k = 1;
  for (int i = 1; i < nums.size(); i++)
  {
   if (nums[i] != nums[i - 1])
   {
    nums[k++] = nums[i];
   }
  }
  return k;
 }
};