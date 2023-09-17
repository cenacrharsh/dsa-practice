#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
 int findMin(vector<int> &nums)
 {
  int n = nums.size();
  int l = 0;
  int r = n - 1;
  while (l < r)
  {
   // if array already sorted
   if (nums[l] < nums[r])
   {
    return nums[l];
   }

   int mid = l + (r - l) / 2;

   if (nums[mid] > nums[r])
   {
    l = mid + 1; // since nums[mid] > nums[r] it definitely can't be min element therefore we can do mid + 1
   }
   else if (nums[mid] < nums[r])
   {
    r = mid; // we can't do mid - 1 as this might be the smallest element
   }
   else
   {
    r--; // l++ will give error if array not rotated
   }
  }
  return nums[r];
 }
};