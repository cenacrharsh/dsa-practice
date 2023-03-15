#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//* Number of operations == Number of non-zero elements
class Solution
{
public:
 void moveZeroes(vector<int> &nums)
 {
  // number of operations == number of non zero elements
  int lastNonZeroFoundAt = 0;
  for (int curr = 0; curr < nums.size(); curr++)
  {
   if (nums[curr] != 0)
   {
    swap(nums[lastNonZeroFoundAt], nums[curr]);
    lastNonZeroFoundAt++;
   }
  }
 }
};

//* Number of operations == Number of zeroes elements
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