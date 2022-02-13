#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Tutorial : https://www.youtube.com/watch?v=qnoOu5Usb4o&t=770s
class Solution
{
public:
 int kadane(vector<int> &arr, bool IsTwice)
 {
  long long M = 1000000007;
  int n = arr.size();
  int cSum = INT_MIN; // currentSum
  int mSum = INT_MIN; // maxSum

  for (int j = 0; j < (IsTwice ? 2 : 1); j++)
  {
   for (int i = 0; i < n; i++)
   {
    if (cSum >= 0)
    {
     cSum += arr[i];
    }
    else
    {
     cSum = arr[i];
    }
    if (cSum > mSum)
    {
     mSum = cSum;
    }
    cSum %= M;
    mSum %= M;
   }
  }
  return mSum;
 }

 int kConcatenationMaxSum(vector<int> &arr, int k)
 {
  long long M = 1000000007;
  if (k == 1)
  {
   return kadane(arr, false);
  }

  long long sum = 0;
  for (long long i = 0; i < arr.size(); i++)
  {
   sum = (sum + arr[i]) % M;
  }

  long long ans = 0;

  if (sum >= 0)
  {
   ans = ((kadane(arr, true)) + (((k - 2) * sum) % M)) % M;
  }
  else
  {
   ans = kadane(arr, true);
  }
  if (ans < 0)
  {
   return 0;
  }
  return ans;
 }
};