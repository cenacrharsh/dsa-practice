#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Negative Array

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 vector<int> findDisappearedNumbers(vector<int> &nums)
 {
  for (int i = 0; i < nums.size(); i++)
  {
   int index = abs(nums[i]) - 1;

   nums[index] = -1 * abs(nums[index]);
  }

  vector<int> ans;
  for (int i = 0; i < nums.size(); i++)
  {
   if (nums[i] > 0)
   {
    ans.push_back(i + 1);
   }
  }
  return ans;
 }
};

//! Swapping

class Solution
{
public:
 vector<int> findDisappearedNumbers(vector<int> &nums)
 {
  vector<int> ans;

  for (auto &c : nums)
   while (nums[c - 1] != c)
    swap(c, nums[c - 1]); // swap till correct index place of c is not occupied by c itself

  for (int i = 1; i <= nums.size(); i++)
   if (i != nums[i - 1])
    ans.push_back(i); // correct index place of i is not occupied by i

  return ans;
 }
};