#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! No extra space
class Solution
{
public:
 vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
 {
  int n = mat.size();    // row
  int m = mat[0].size(); // col

  if (n * m != r * c)
  {
   return mat;
  }

  vector<vector<int>> ans(r, vector<int>(c, 0));
  int k = 0;
  for (int i = 0; i < r; i++)
  {
   for (int j = 0; j < c; j++)
   {
    ans[i][j] = mat[k / m][k % m];
    k++;
   }
  }
  return ans;
 }
};

//* or

class Solution
{
public:
 vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
 {
  int n = mat.size();    // row
  int m = mat[0].size(); // col

  if (n * m != r * c)
  {
   return mat;
  }

  vector<vector<int>> ans(r, vector<int>(c, 0));
  int row = 0, col = 0;
  for (int i = 0; i < r; i++)
  {
   for (int j = 0; j < c; j++)
   {
    ans[i][j] = mat[row][col++];
    if (col == m)
    {
     row++;
     col = 0;
    }
   }
  }
  return ans;
 }
};

//! Extra Array
class Solution
{
public:
 vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
 {
  int n = mat.size();    // row
  int m = mat[0].size(); // col

  if (n * m != r * c)
  {
   return mat;
  }

  vector<int> values;
  for (auto row : mat)
  {
   for (auto col : row)
   {
    values.push_back(col);
   }
  }

  vector<vector<int>> ans(r, vector<int>(c, 0));
  int k = 0;
  for (int i = 0; i < r; i++)
  {
   for (int j = 0; j < c; j++)
   {
    ans[i][j] = values[k++];
   }
  }
  return ans;
 }
};