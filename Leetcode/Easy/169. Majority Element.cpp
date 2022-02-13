#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Approach 1 - Moore's Voting Algo

//! Approach 2

class Solution
{
public:
 int majorityElement(vector<int> &nums)
 {
  int size = nums.size();
  sort(nums.begin(), nums.end());
  int maxCount = INT_MIN;
  int ans = -1;
  int i = 0;
  int startVertex = 0;

  while (i < size)
  {
   while (i + 1 < size && nums[i] == nums[i + 1])
   {
    i++;
   }
   int tempCount = i - startVertex + 1;
   if (tempCount > maxCount)
   {
    maxCount = tempCount;
    ans = nums[i];
   }
   startVertex = i + 1;
   i++;
  }

  int requiredCount = size / 2;
  if (maxCount > requiredCount)
  {
   return ans;
  }
  else
  {
   return -1;
  }
 }
};