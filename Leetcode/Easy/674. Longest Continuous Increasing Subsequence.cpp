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
 int findLengthOfLCIS(vector<int> &nums)
 {
  int i = 1;
  int maxCount = 1;
  while (i < nums.size())
  {
   if (nums[i] > nums[i - 1])
   {
    int count = 1;
    while (i < nums.size() && nums[i] > nums[i - 1])
    {
     count++;
     i++;
    }
    maxCount = max(maxCount, count);
   }
   i++;
  }
  return maxCount;
 }
};