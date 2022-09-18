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
 bool canJump(vector<int> &nums)
 {
  int n = nums.size();
  int lastGoodIndexPosition = n - 1;
  for (int currIndex = n - 1; currIndex >= 0; currIndex--)
  {
   if (currIndex + nums[currIndex] >= lastGoodIndexPosition)
   {
    lastGoodIndexPosition = currIndex;
   }
  }
  return (lastGoodIndexPosition == 0 ? true : false);
 }
};

// bool canJump(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n);
//     dp[n-1] = 1;
//     int lastIndex = n-1;
//     for(int currIndex = n - 1; currIndex >= 0; currIndex--)
//     {
//         if(currIndex + nums[currIndex] >= lastIndex)
//         {
//             dp[currIndex] = 1;
//             lastIndex = currIndex;
//         }
//     }
//     return (dp[0] == 1 ? true : false);
// }