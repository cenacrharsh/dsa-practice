#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

/*
> Time Complexity: O(log n)
> Space Complexity: O(1)
*/

//! Approach 1
class Solution
{
public:
 int search(vector<int> &nums, int target)
 {
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r)
  {
   int mid = l + (r - l) / 2;
   if (nums[mid] == target)
   {
    return mid;
   }
   else if (target < nums[mid])
   {
    r = mid - 1;
   }
   else if (target > nums[mid])
   {
    l = mid + 1;
   }
  }
  return -1;
 }
};

//! Approach 2
class Solution
{
public:
 int search(vector<int> &nums, int target)
 {
  int low = 0, high = nums.size() - 1;
  // terminate loop when only 2 elements left in search space
  while (high - low > 1)
  {
   int mid = low + (high - low) / 2;
   if (nums[mid] < target)
   {
    low = mid + 1;
   }
   else
   {
    // nums[mid] >= target
    high = mid;
   }
  }
  if (nums[low] == target)
   return low;
  else if (nums[high] == target)
   return high;
  else
   return -1;
 }
};