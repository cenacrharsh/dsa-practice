#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
for subarray sum of (3, 5) -> (0, 5) - (0, 2), so sum1 - sum2 will give us a subarray sum and % k = 0 indicates that sum is a multiple fo k
(sum1 - sum2) % k = 0
sum1 % k = sum2 % k
use hashmap of sum -> index
store sum = sum % k
once we find a sum we have seen already, we know that the subarray sum if a multiple of k, just chk is size is atleast 2
*/

//# Tutorial: https://www.youtube.com/watch?v=OKcrLfR-8mE, https://www.youtube.com/watch?v=wsTcByj8QbI

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 bool checkSubarraySum(vector<int> &nums, int k)
 {
  unordered_map<int, int> prefixSumRemainderMap; //* sum -> index
  prefixSumRemainderMap[0] = -1;
  int prefixSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   prefixSum += nums[i];

   if (k != 0)
   {
    prefixSum = prefixSum % k;
   }

   if (prefixSumRemainderMap.find(prefixSum) != prefixSumRemainderMap.end())
   {
    // (3, 5) -> (0, 5) - (0, 2), no of elements b/w 3->5 is 3 i.e. 5 - 2 = 3
    if ((i - prefixSumRemainderMap[prefixSum]) >= 2)
    {
     return true;
    }
   }
   else
   {
    prefixSumRemainderMap[prefixSum] = i;
   }
  }
  return false;
 }
};