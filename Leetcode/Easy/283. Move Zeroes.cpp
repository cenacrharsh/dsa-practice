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
 void moveZeroes(vector<int> &nums)
 {
  int cnt = 0;
  int k = 0;

  for (int i = 0; i < nums.size(); i++)
  {
   if (nums[i] != 0)
   {
    nums[k++] = nums[i];
   }
   else
   {
    cnt++;
   }
  }

  for (int i = 0; i < cnt; i++)
  {
   nums[k++] = 0;
  }
 }
};