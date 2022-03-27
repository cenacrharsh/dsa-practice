#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

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