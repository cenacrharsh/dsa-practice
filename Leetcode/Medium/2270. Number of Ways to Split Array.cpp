#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution

class Solution
{
public:
 int waysToSplitArray(vector<int> &nums)
 {
  int n = nums.size();
  vector<long long int> suffix(n);
  int count = 0;
  suffix[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--)
  {
   suffix[i] = nums[i + 1] + suffix[i + 1];
  }
  long long int prefix = 0;
  for (int i = 0; i < n - 1; i++)
  {
   prefix += nums[i];
   if (prefix >= suffix[i])
   {
    count++;
   }
  }
  return count;
 }
};