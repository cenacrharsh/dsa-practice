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
 vector<int> sortArrayByParity(vector<int> &nums)
 {
  int n = nums.size();
  int i = 0, j = 0;
  while (j < n)
  {
   if (nums[j] % 2 == 0)
   {
    swap(nums[i], nums[j]);
    i++;
   }
   j++;
  }
  return nums;
 }
};