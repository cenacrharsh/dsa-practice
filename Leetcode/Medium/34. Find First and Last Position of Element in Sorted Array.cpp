#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution
{
public:
 int findFirstPosition(vector<int> &nums, int target)
 {
  int low = 0, high = nums.size() - 1;
  while (low <= high)
  {
   int mid = low + (high - low) / 2;
   if (target == nums[mid])
   {
    if (mid - 1 >= 0 && target == nums[mid - 1])
    {
     high = mid - 1;
    }
    else
    {
     return mid;
    }
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
  return -1;
 }
 int findLastPosition(vector<int> &nums, int target)
 {
  int low = 0, high = nums.size() - 1;
  while (low <= high)
  {
   int mid = low + (high - low) / 2;
   if (target == nums[mid])
   {
    if (mid + 1 < nums.size() && target == nums[mid + 1])
    {
     low = mid + 1;
    }
    else
    {
     return mid;
    }
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
  return -1;
 }
 vector<int> searchRange(vector<int> &nums, int target)
 {
  vector<int> ans(2, 0);
  ans[0] = findFirstPosition(nums, target);
  ans[1] = findLastPosition(nums, target);
  return ans;
 }
};
//* or
class Solution
{
public:
 vector<int> searchRange(vector<int> &nums, int target)
 {
  vector<int> pos(2, -1);
  int n = nums.size();
  int fp = -1;
  int lp = -1;

  int l = 0;
  int r = n - 1;
  while (l <= r)
  {
   int mid = l + (r - l) / 2;
   if (nums[mid] == target)
   {
    if ((mid - 1 >= l) && (nums[mid - 1] == target))
    {
     r = mid - 1;
    }
    else
    {
     fp = mid;
     break;
    }
   }
   else if (target <= nums[mid])
   {
    r = mid - 1;
   }
   else if (target > nums[mid])
   {
    l = mid + 1;
   }
  }

  l = 0;
  r = n - 1;
  while (l <= r)
  {
   int mid = l + (r - l) / 2;
   if (nums[mid] == target)
   {
    if ((mid + 1 <= r) && (nums[mid + 1] == target))
    {
     l = mid + 1;
    }
    else
    {
     lp = mid;
     break;
    }
   }
   else if (target <= nums[mid])
   {
    r = mid - 1;
   }
   else if (target > nums[mid])
   {
    l = mid + 1;
   }
  }

  pos[0] = fp;
  pos[1] = lp;
  return pos;
 }
};