#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 bool check(vector<int> &nums)
 {
  // sorted array has 0 break points
  // sorted and rotated array has 1 break point
  int count = 0;
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
   if (nums[i] > nums[(i + 1) % n])
    count++;
  }
  return (count <= 1);
 }
};