#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 2 pointers

class Solution
{
public:
 int maxOperations(vector<int> &nums, int k)
 {
  sort(nums.begin(), nums.end());
  int l = 0, r = nums.size() - 1, count = 0;
  while (l < r)
  {
   int tempSum = nums[l] + nums[r];
   if (tempSum == k)
   {
    count++;
    l++;
    r--;
   }
   else if (tempSum < k)
   {
    l++;
   }
   else if (tempSum > k)
   {
    r--;
   }
  }
  return count;
 }
};