#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=qgizvmgeyUM

/*
> Time Complexity: O(n) + O(n) + O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 int longestConsecutive(vector<int> &nums)
 {
  unordered_set<int> seq(nums.begin(), nums.end());
  int maxLen = 0;
  for (auto num : nums)
  {
   if (seq.find(num - 1) == seq.end())
   {
    int len = 0;
    int currNum = num;
    while (seq.find(currNum) != seq.end())
    {
     len++;
     currNum++;
    }
    maxLen = max(maxLen, len);
   }
  }
  return maxLen;
 }
};