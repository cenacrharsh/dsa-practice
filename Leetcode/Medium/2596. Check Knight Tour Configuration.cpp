#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ptBWFn7yR0U

class Solution
{
public:
 bool checkValidGrid(vector<vector<int>> &grid)
 {
  int n = grid.size();

  // knight must start from the leftmost index
  if (grid[0][0] != 0)
  {
   return false;
  }

  // to store all the (x,y) coordinates of each move
  vector<vector<int>> coordinates(n * n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < n; j++)
   {
    coordinates[grid[i][j]][0] = i;
    coordinates[grid[i][j]][1] = j;
   }
  }

  // now check from 1 => n^2 - 1 if it's possible to come to current step from previous step
  for (int i = 1; i < n * n; i++)
  {
   int x = abs(coordinates[i - 1][0] - coordinates[i][0]);
   int y = abs(coordinates[i - 1][1] - coordinates[i][1]);

   // sum of abs diff of x and y coordinates for valid moves = 3
   int chk = x + y;

   // for a valid step sum should be == 3 but any individual x or y should not be 3
   if (chk != 3 || x == 3 || y == 3)
   {
    return false;
   }
  }
  return true;
 }
};