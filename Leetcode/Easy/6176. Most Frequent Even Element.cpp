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
 int mostFrequentEven(vector<int>& nums)
 {
  unordered_map<int, int> freq;
  int ans = INT_MIN;
  int max_freq = INT_MIN;
  sort(nums.begin(), nums.end());
  for (int i = nums.size() - 1; i >= 0; i--)
  {
   if (nums[i] % 2 == 0)
   {
    freq[nums[i]]++;
    if (freq.find(nums[i]) != freq.end())
    {
     if (freq[nums[i]] >= max_freq)
     {
      max_freq = freq[nums[i]];
      ans = nums[i];
     }
    }
   }
  }
  if (ans == INT_MIN)
  {
   return -1;
  }
  else
  {
   return ans;
  }
 }
};