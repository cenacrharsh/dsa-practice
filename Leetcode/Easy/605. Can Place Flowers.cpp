#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 bool canPlaceFlowers(vector<int> &flowerbed, int n)
 {
  int count = 0;
  int len = flowerbed.size();
  for (int i = 0; i < len; i++)
  {
   // check if the current plot is empty
   if (flowerbed[i] == 0)
   {
    // check if it's left and right plots are empty;
    bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
    bool emptyRightPlot = (i == len - 1) || (flowerbed[i + 1] == 0);

    // if both plots are empty, we can plant a flower there
    if (emptyLeftPlot && emptyRightPlot)
    {
     flowerbed[i] = 1;
     count++;

     // if count increases n, we return true
     if (count >= n)
     {
      return true;
     }
    }
   }
  }
  return count >= n;
 }
};