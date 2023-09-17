#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
 int trap(vector<int> &height)
 {
  int leftMax = INT_MIN;
  int rightMax = INT_MIN;
  int water = 0;
  int l = 0, r = height.size() - 1;
  while (l <= r)
  {
   if (height[l] <= height[r])
   {
    if (height[l] >= leftMax)
    {
     leftMax = height[l];
    }
    else
    {
     water += leftMax - height[l];
    }
    l++;
   }
   else if (height[r] < height[l])
   {
    if (height[r] >= rightMax)
    {
     rightMax = height[r];
    }
    else
    {
     water += rightMax - height[r];
    }
    r--;
   }
  }
  return water;
 }
};