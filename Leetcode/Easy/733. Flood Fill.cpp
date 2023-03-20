#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=C-2_uSRli8o

//! Using DFS

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n*m) + O(n*m) => auxiliary stack space
*/

class Solution
{
private:
 void dfs(vector<vector<int>> &image, int row, int col, int newColor, vector<vector<int>> &ans, int initialColor, int deltaRow[], int deltaCol[])
 {
  // set the newColor at our starting coordinate
  ans[row][col] = newColor;

  int n = image.size();
  int m = image[0].size();

  // we have 4 directions
  for (int i = 0; i < 4; i++)
  {
   int newRow = row + deltaRow[i];
   int newCol = col + deltaCol[i];
   if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == initialColor && ans[newRow][newCol] != newColor)
   {
    // call the func with new value of row and col
    dfs(image, newRow, newCol, newColor, ans, initialColor, deltaRow, deltaCol);
   }
  }
 }

public:
 vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
 {
  int initialColor = image[sr][sc];
  vector<vector<int>> ans = image;
  // up: (row-1, col)
  // right: (row, col+1)
  // down: (row+1, col)
  // left: (row, col-1)
  int deltaRow[] = {-1, 0, 1, 0};
  int deltaCol[] = {0, 1, 0, -1};
  dfs(image, sr, sc, color, ans, initialColor, deltaRow, deltaCol);
  return ans;
 }
};