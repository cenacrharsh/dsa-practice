#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
 int maximumDifference(vector<int> &nums)
 {
  int n = nums.size();
  int currentMinimumElement = nums[0];
  int maxDifference = -1;
  for (int i = 1; i < n; i++)
  {
   if (currentMinimumElement != nums[i])
   {
    int tempDifference = nums[i] - currentMinimumElement;
    maxDifference = max(maxDifference, tempDifference);
    // updating the minimum element
    currentMinimumElement = min(currentMinimumElement, nums[i]);
   }
  }
  return maxDifference;
 }
};