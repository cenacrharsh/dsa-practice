#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=KaOHilx0mlg

class Solution
{
public:
 int countLatticePoints(vector<vector<int>> &circles)
 {
  int count = 0;
  for (int i = 0; i <= 200; i++)
  {
   for (int j = 0; j <= 200; j++)
   {
    bool flag = false;
    for (int k = 0; k < circles.size(); k++)
    {
     int x = circles[k][0];
     int y = circles[k][1];
     int r = circles[k][2];

     if (((x - i) * (x - i) + (y - j) * (y - j)) <= r * r)
     {
      flag = true;
     }
    }
    if (flag)
    {
     count++;
    }
   }
  }
  return count;
 }
};