#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=CoDBIX5TCow

class Solution
{
public:
 bool check(vector<int> &weights, int days, int capacity)
 {
  int requiredDays = 1;
  int currentWeight = 0;
  for (int i : weights)
  {
   if (currentWeight + i > capacity)
   {
    requiredDays++;
    currentWeight = 0;
   }
   currentWeight += i;
  }
  return requiredDays <= days ? true : false;
 }

 int shipWithinDays(vector<int> &weights, int days)
 {
  // we do binary search from lowest possible capacity which is the max weight package in the lot, to highest possible capacity that is the sum total of all packages
  int maxWeight = INT_MIN;
  int totalWeight = 0;
  int ans;
  for (int i : weights)
  {
   maxWeight = max(maxWeight, i);
   totalWeight += i;
  }
  int left = maxWeight;
  int right = totalWeight;
  while (left <= right)
  {
   int mid = (left + right) / 2;

   if (check(weights, days, mid))
   {
    ans = mid;
    // try and see if it still works if we reduce the capaciy
    right = mid - 1;
   }
   else
   {
    left = mid + 1;
   }
  }
  return ans;
 }
};