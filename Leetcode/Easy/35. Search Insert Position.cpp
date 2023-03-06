#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Lower Bound Implemented
class Solution
{
public:
 int searchInsert(vector<int> &nums, int target)
 {
  int n = nums.size();
  int low = 0, high = n - 1;
  if (target > nums[n - 1])
  {
   return n;
  }
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
  if (nums[low] >= target)
  {
   return low;
  }
  else if (nums[high] >= target)
  {
   return high;
  }
  return -1;
 }
};

//* or

class Solution
{
public:
 int searchInsert(vector<int> &nums, int target)
 {
  int n = nums.size();
  int low = 0, high = n - 1;
  if (target > nums[n - 1])
  {
   return n;
  }
  while (low <= high)
  {
   int mid = low + (high - low) / 2;
   cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
   if (target == nums[mid])
   {
    return mid; // if found return its position
   }
   else if (target < nums[mid])
   {
    high = mid - 1;
   }
   else if (target > nums[mid])
   {
    low = mid + 1;
   }
  }
  return low; // if not found return the location where it should be
 }
};

//! Lower Bound STL
class Solution
{
public:
 int searchInsert(vector<int> &nums, int target)
 {
  int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
  return index;
 }
};