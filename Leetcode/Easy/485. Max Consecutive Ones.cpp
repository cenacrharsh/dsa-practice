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
 int findMaxConsecutiveOnes(vector<int> &nums)
 {
  int maxCount = 0;
  int i = 0;
  while (i < nums.size())
  {
   if (nums[i] == 1)
   {
    int count = 0;
    while (i < nums.size() && nums[i] == 1)
    {
     i++;
     count++;
    }
    maxCount = max(maxCount, count);
   }
   i++;
  }
  return maxCount;
 }
};