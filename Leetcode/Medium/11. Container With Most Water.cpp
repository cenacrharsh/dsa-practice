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
 int maxArea(vector<int> &height)
 {
  int maxWater = INT_MIN;
  int l = 0, r = height.size() - 1;
  while (l < r)
  {
   int water = 0;
   if (height[l] < height[r])
   {
    water = height[l] * (r - l);
    l++;
   }
   else
   {
    water = height[r] * (r - l);
    r--;
   }
   maxWater = max(maxWater, water);
  }
  return maxWater;
 }
};