#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=o8S2bO3pmO4

//! Using DFS
class Solution
{
public:
 int dfs(vector<vector<char>> &grid, int row, int col)
 {
  // if we move out of bounds or hit a water cell, we return 0
  if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
  {
   return 0;
  }

  // marking the current cell as 0 so it doesn't get counted again
  grid[row][col] = '0';

  // now we move to all 4 directions to count all connected 1's as one unit
  dfs(grid, row - 1, col); // up
  dfs(grid, row, col + 1); // right
  dfs(grid, row + 1, col); // down
  dfs(grid, row, col - 1); // left

  return 1; // to count the one island we have already visited, but we make sure we cover all other connected 1's
 }

 int numIslands(vector<vector<char>> &grid)
 {
  int numIslands = 0;
  for (int i = 0; i < grid.size(); i++)
  {
   for (int j = 0; j < grid[0].size(); j++)
   {
    if (grid[i][j] == '1')
    {
     numIslands += dfs(grid, i, j);
    }
   }
  }
  return numIslands;
 }
};