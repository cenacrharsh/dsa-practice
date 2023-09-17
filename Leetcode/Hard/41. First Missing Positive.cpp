#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=2QugZILS_Q8

//! Using Negative Array

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int firstMissingPositive(vector<int> &nums)
 {
  //* preprocessing
  int n = nums.size();
  bool oneExists = false;
  for (int i = 0; i < n; i++)
  {
   if (nums[i] == 1)
   {
    oneExists = true;
   }
  }

  if (oneExists == false)
  {
   return 1;
  }

  //* make all 0's, -ve and large indexes ( > n) = 1
  for (int i = 0; i < n; i++)
  {
   if (nums[i] <= 0 || nums[i] > n)
   {
    nums[i] = 1;
   }
  }

  //* marking all indexes corresponding to which number already exists
  for (int i = 0; i < n; i++)
  {
   int index = abs(nums[i]); // nums[i] could have been negated already
   if (index < n)
   {
    nums[index] = -1 * abs(nums[index]);
   }
   else
   {
    // for nth index we use 0th spot, we can do that as we already removed all 0's
    nums[0] = -1 * abs(nums[0]);
   }
  }

  for (int i = 1; i < n; i++)
  {
   if (nums[i] > 0)
   {
    return i;
   }
  }

  if (nums[0] > 0)
  {
   return n;
  }

  return n + 1; // [1,2,3] -> ans is 4
 }
};

//! Swapping

/*
Put each number in its right place.

For example:

When we find 5, then swap it with A[4].

At last, the first place where its number is not right, return the place + 1.
*/

class Solution
{
public:
 int firstMissingPositive(vector<int> &nums)
 {
  int i = 0;
  int n = nums.size();
  while (i < n)
  {
   //* check if val of nums[i] is a valid index value withing bounds, and if the index at which it is to be placed already contains this value (in case of duplicate members), if both not true then place it in it's correct place
   if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
    swap(nums[i], nums[nums[i] - 1]);
   else
    i++;
  }

  for (i = 0; i < n; ++i)
   if (nums[i] != (i + 1)) //* first index not containing correct element is the ans
    return i + 1;

  return n + 1; //* if all at it's correct pos then all integers b/w [1,n] exist so n + 1 is the first +ve integer missng
 }
};

//! Using Hashmap

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 int firstMissingPositive(vector<int> &nums)
 {
  unordered_set<int> num(nums.begin(), nums.end());
  int i = 1;
  while (true)
  {
   if (num.find(i) == num.end())
   {
    return i;
   }
   i++;
  }
 }
};