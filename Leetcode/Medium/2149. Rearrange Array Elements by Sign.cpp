#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

//! Use 2pointers
class Solution
{
public:
 vector<int> rearrangeArray(vector<int> &nums)
 {
  int n = nums.size();
  int pos = 0, neg = 1;
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++)
  {
   if (nums[i] > 0)
   {
    ans[pos] = nums[i];
    pos += 2;
   }
   else
   {
    ans[neg] = nums[i];
    neg += 2;
   }
  }
  return ans;
 }
};

//! Create separate arrays to store +ve and -ve numbers
class Solution
{
public:
 vector<int> rearrangeArray(vector<int> &nums)
 {
  int n = nums.size();
  vector<int> pos, neg;
  for (auto num : nums)
  {
   if (num > 0)
   {
    pos.push_back(num);
   }
   else
   {
    neg.push_back(num);
   }
  }
  int k = 0;
  for (int i = 0; i < n; i += 2)
  {
   nums[i] = pos[k];
   nums[i + 1] = neg[k];
   k++;
  }
  return nums;
 }
};