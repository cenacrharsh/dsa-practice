#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Upper Bound and Lower Bound
//> index of element either = or just greater than target
/*
Vector contains : 10 20 30 30 30 40 50

lower_bound for element 30 at position : 2
lower_bound for element 35 at position : 5
lower_bound for element 55 at position : 7
*/
int lower_bound(vector<int> &v, int target)
{
  int low = 0, high = v.size() - 1;
  while (high - low > 1)
  {
    int mid = low + (high - low) / 2;
    if (v[mid] < target)
    {
      low = mid + 1;
    }
    else
    {
      //* v[mid] >= target
      high = mid;
    }
  }
  //> since lower bound means element which is either = or just greater than target, we have to compare with low first as if both low and high are eligible then low is our ans as it comes first
  if (v[low] >= target)
  {
    return low;
  }
  if (v[high] >= target)
  {
    return high;
  }
  return -1;
}

//> first element that is bigger than target
/*
Vector contains : 10 20 30 40 50

upper_bound for element 35 is at position : 3
upper_bound for element 45 is at position : 4
*/
int upper_bound(vector<int> &v, int target)
{
  int low = 0, high = v.size() - 1;
  while (high - low > 1)
  {
    int mid = low + (high - low) / 2;
    // we have to eleminate elements <= target also
    if (v[mid] <= target)
    {
      low = mid + 1;
    }
    else
    {
      //* v[mid] > target
      high = mid;
    }
  }
  //> since lower bound means element which is either = or just greater than target, we have to compare with low first as if both low and high are eligible then low is our ans as it comes first
  if (v[low] > target)
  {
    return low;
  }
  if (v[high] > target)
  {
    return high;
  }
  return -1;
}

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