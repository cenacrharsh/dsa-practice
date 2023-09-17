#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
 int search(vector<int> &nums, int target)
 {
  int start = 0;
  int end = nums.size() - 1;

  // performing binary search
  while (start <= end)
  {
   int mid = start + (end - start) / 2;
   if (nums[mid] == target)
   {
    return mid;
   }

   // now we find out which halve is sorted

   // if first halve is sorted
   else if (nums[mid] >= nums[start])
   {
    if (target >= nums[start] && target <= nums[mid])
    {
     end = mid - 1;
    }
    else
    {
     start = mid + 1;
    }
   }

   // if second halve is sorted
   else if (nums[end] >= nums[mid])
   {
    if (target >= nums[mid] && target <= nums[end])
    {
     start = mid + 1;
    }
    else
    {
     end = mid - 1;
    }
   }
  }
  return -1;
 }
};