#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=22CfEGAetpQ

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 long long zeroFilledSubarray(vector<int> &nums)
 {
  long long int ans = 0;
  int count = 0; // to keep track of continous 0's
  for (int num : nums)
  {
   if (num != 0)
   {
    count = 0; // reset the count of 0
   }
   else
   {
    count++; // to count continous 0's
   }
   ans += count;
  }
  return ans;
 }
};