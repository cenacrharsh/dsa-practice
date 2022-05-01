#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution

class Solution
{
public:
 int minimumAverageDifference(vector<int> &nums)
 {
  int n = nums.size();
  vector<long long int> suffixSum(n);
  int minAvg = INT_MAX;
  int minIndex = INT_MAX;
  suffixSum[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--)
  {
   suffixSum[i] = nums[i + 1] + suffixSum[i + 1];
  }
  long long int sum = 0;
  for (int i = 0; i < n; i++)
  {
   sum += nums[i];
   int a = sum / (i + 1);
   int b;
   if (n - i - 1 != 0)
   {
    b = suffixSum[i] / (n - i - 1);
   }
   else
   {
    b = 0;
   }
   int avg = abs(a - b);
   if (avg < minAvg)
   {
    minAvg = avg;
    minIndex = i;
   }
  }
  return minIndex;
 }
};