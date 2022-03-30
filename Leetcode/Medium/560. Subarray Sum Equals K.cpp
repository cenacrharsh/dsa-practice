#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//# Tutorial - https://www.youtube.com/watch?v=20v8zSo2v18

class Solution
{
public:
 int subarraySum(vector<int> &nums, int k)
 {
  int count = 0;
  int prefixSum = 0;
  unordered_map<int, int> prefixSumMap; // prefixSum -> freq
  prefixSumMap[prefixSum] = 1;
  for (int i = 0; i < nums.size(); i++)
  {
   prefixSum += nums[i];

   if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end())
   {
    count += prefixSumMap[prefixSum - k];
   }

   prefixSumMap[prefixSum]++;
  }
  return count;
 }
};

#include <unordered_map>

class Solution
{
public:
 int subarraySum(vector<int> &nums, int k)
 {
  unordered_map<int, int> sumMap;
  sumMap[0] = 1;
  /* initial sum = 0, therefore frequency of sum = 0 is up by 1 */
  int count = 0;
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   sum = sum + nums[i];
   int diff = sum - k;
   /* check if sum - k exists in hashmap, sum - k indicates that the subarray between the position where sum - k occured and upto the current position, the subarray sum = k -----> sum - (sum - k) = k */
   if (sumMap.find(diff) != sumMap.end())
   {
    count += sumMap[diff];
   }

   /* updating the frequency of sum, if it occurs for the first time set it equal to 1, else if it has occured previously then add 1 to the existing frequency */
   if (sumMap.find(sum) != sumMap.end())
   {
    sumMap[sum] += 1;
   }
   else
   {
    /* if sum doesn't already exist */
    sumMap[sum] = 1;
   }
  }
  return count;
 }
};

// Write your code here.
// int count = 0;
// for(int i = 0;i < arr.size();i++)
// {
//     int temp_sum = 0;
//     for(int j = i;j < arr.size();j++)
//     {
//         temp_sum += arr[j];
//         if(temp_sum == k)
//         {
//             count++;
//         }
//     }
// }
// return count;
// }
//     int count = 0;
//     int n = nums.size();
//     int sum[n+1];
//     sum[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//     sum[i] = sum[i - 1] + nums[i - 1];
//     }
//     for (int start = 0; start < n; start++)
//     {
//         for (int end = start + 1; end <= n; end++)             {
//             if (sum[end] - sum[start] == k)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }