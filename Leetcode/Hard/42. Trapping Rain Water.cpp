#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
- For every building we can only store water if there is a taller building to it's left and right.
- Total Water = Summation (0->n-1) min(leftMax, rightMax) - arr[i], and the main challenge is to find the leftMax and rightMax for each building in optimal time.
*/

class Solution
{
public:
  int trap(vector<int> &height)
  {
    int leftMax = 0, rightMax = 0, left = 0, right = height.size() - 1, totalWater = 0;
    while (left <= right)
    {
      //* since we always deal with whichever one on either left or right is smaller we are always sure of the fact that if we are currently operating on left it's assured that a height >= currHeight exists in right
      if (height[left] <= height[right])
      {
        if (leftMax > height[left])
        {
          totalWater += (leftMax - height[left]);
        }
        else
        {
          leftMax = height[left];
        }
        left++;
      }
      else
      {
        if (rightMax > height[right])
        {
          totalWater += (rightMax - height[right]);
        }
        else
        {
          rightMax = height[right];
        }
        right--;
      }
    }
    return totalWater;
  }
};