#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=QPfalDbqa4A

class Solution
{
public:
 int longestOnes(vector<int> &nums, int k)
 {
  int zeroes = 0, ans = 0, j = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   if (nums[i] == 0)
    zeroes++;

   while (zeroes > k)
   {
    if (nums[j] == 0)
     zeroes--;
    j++;
   }

   int len = i - j + 1;
   ans = max(ans, len);
  }
  return ans;
 }
};