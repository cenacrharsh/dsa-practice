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
 int missingNumber(vector<int> &nums)
 {
  int missing = nums.size(); // adding n beforehand
  for (int i = 0; i < nums.size(); i++)
  {
   missing ^= i;
   missing ^= nums[i];
  }
  return missing;
 }
};