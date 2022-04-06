#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#define ll long long

class Solution
{
public:
 // Function to count subarrays with sum equal to 0.
 ll findSubarray(vector<ll> arr, int n)
 {
  // code here
  unordered_map<ll, ll> prefixSumMap; // sum -> index
  ll sum = 0;
  ll count = 0;
  prefixSumMap[0] = 1;
  for (ll i = 0; i < n; i++)
  {
   sum += arr[i];
   if (prefixSumMap.find(sum) != prefixSumMap.end())
   {
    count += prefixSumMap[sum];
   }

   prefixSumMap[sum]++;
  }
  return count;
 }
};