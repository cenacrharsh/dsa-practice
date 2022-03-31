#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial : https://www.youtube.com/watch?v=A98psR_mIMQ

//! Shift Index = i - deletions

class Solution
{
public:
 int minDeletion(vector<int> &nums)
 {
  int deletions = 0;
  int n = nums.size();
  //* we don't need to check for last element, as it has no i+1 th element
  for (int i = 0; i < n - 1; i++)
  {
   int shiftIndex = i - deletions;
   //* if the new index of element in even and the next element is = then deletions++
   if ((shiftIndex % 2 == 0) && (nums[i] == nums[i + 1]))
   {
    deletions++;
   }
  }

  //* if after deletion array has odd no. of elements we drop the last element as we want a even sized array
  if ((n - deletions) % 2 == 1)
  {
   deletions++;
  }

  return deletions;
 }
};

//! 2 ptrs

class Solution
{
public:
 int minDeletion(vector<int> &nums)
 {
  if (nums.size() == 0)
  {
   return 0;
  }
  int n = nums.size();
  int count = 0;
  int curr = 0, next = 1;
  int newSize = n;
  while (next < n)
  {
   if (nums[curr] == nums[next])
   {
    count++;
    newSize--;
    next++;
    continue;
   }
   curr = next + 1;
   next = next + 2;
  }
  if (newSize % 2 == 0)
  {
   return count;
  }
  else
  {
   return count + 1;
  }
 }
};