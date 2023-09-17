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
 int maxSum(vector<vector<int>> &grid)
 {
  int sum = 0;
  int maxSum = INT_MIN;
  for (int i = 0; i < grid.size() - 2; i++)
  {
   for (int j = 0; j < grid[i].size() - 2; j++)
   {
    int temp1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
    int temp2 = grid[i + 1][j + 1];
    int temp3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
    sum = temp1 + temp2 + temp3;
    maxSum = max(sum, maxSum);
   }
  }
  return maxSum;
 }
};