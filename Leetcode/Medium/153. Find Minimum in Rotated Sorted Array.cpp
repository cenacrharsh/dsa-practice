#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Using Binary Search

/*
> Time Complexity: O(log n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int findMin(vector<int> &nums)
 {
  int n = nums.size();
  int l = 0;
  int r = n - 1;
  while (l <= r)
  {
   // if array already sorted
   if (nums[l] <= nums[r])
   {
    return nums[l];
   }

   int mid = l + (r - l) / 2;
   int next = (mid + 1) % n;     // (n-1 + 1) % n = 0
   int prev = (mid - 1 + n) % n; // (0 - 1 + n) % n = n - 1

   // mid lies at pivot element
   if (nums[prev] > nums[mid] && nums[next] > nums[mid])
   {
    return nums[mid];
   }
   // mid lies to left of pivot
   else if (nums[mid] > nums[r])
   {
    l = mid + 1;
   }
   // mid lies to right of pivot
   else if (nums[mid] < nums[r])
   {
    r = mid - 1;
   }
  }
  return -1;
 }
};