#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=W8VuDt0eb5c

//! Using DFS

class Solution
{
public:
 int dfs(vector<vector<int>> &grid, int row, int col)
 {
  // if our cell is out of bonds or == 0 i.e. water, we return
  if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
  {
   return 0;
  }

  // we set the cell == 0 as we don't want to count it again later
  grid[row][col] = 0;

  // we know we are at a 1, so count initially = 1
  int count = 1;
  int deltaRow[] = {-1, 0, 1, 0};
  int deltaCol[] = {0, 1, 0, -1};
  for (int i = 0; i < 4; i++)
  {
   int newRow = row + deltaRow[i];
   int newCol = col + deltaCol[i];
   count += dfs(grid, newRow, newCol);
  }
  return count;
 }
 int maxAreaOfIsland(vector<vector<int>> &grid)
 {
  int maxArea = 0;
  for (int i = 0; i < grid.size(); i++)
  {
   for (int j = 0; j < grid[0].size(); j++)
   {
    // if our current cell is 1 we run a dfs on it to try and connect all the lands we can and get maximum area
    if (grid[i][j] == 1)
    {
     maxArea = max(maxArea, dfs(grid, i, j));
    }
   }
  }
  return maxArea;
 }
};