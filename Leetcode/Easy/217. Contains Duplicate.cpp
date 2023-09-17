#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using unordered_map
class Solution
{
public:
 bool containsDuplicate(vector<int> &nums)
 {
  unordered_map<int, int> freq;
  for (int i = 0; i < nums.size(); i++)
  {
   freq[nums[i]]++;
   if (freq[nums[i]] > 1)
   {
    return true;
   }
  }
  return false;
 }
};