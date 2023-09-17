#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=10

/*
> Time Complexity: O(n) + O(n) + O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 void nextPermutation(vector<int> &nums)
 {
  // step-1 Find the breakpoint
  int n = nums.size();
  int i, j;
  for (i = n - 2; i >= 0; i--)
  {
   if (nums[i] < nums[i + 1])
   {
    break;
   }
  }
  
  // step-2 find number just greater than breakpoint after breakpoint in array, and if no breakpoint return the smallest permutation possible
  if (i < 0)
  {
   reverse(nums.begin(), nums.end());
  }
  else
  {
   for (j = n - 1; j > i; j--)
   {
    if (nums[j] > nums[i])
    {
     break;
    }
   }

   // step-3 swap the 2 indices
   swap(nums[i], nums[j]);

   // step-4 reverse the part of arr to the right of breakpoint, as after swap we already have the next big number so to get the very next number we make sure the left over part is as small as possible, so from des order to asc
   reverse(nums.begin() + i + 1, nums.end());
  }
 }
};