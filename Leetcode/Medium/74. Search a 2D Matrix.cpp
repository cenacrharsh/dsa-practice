#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ZYpYur0znng

//! Approach 1

class Solution
{
public:
 bool searchMatrix(vector<vector<int>> &matrix, int target)
 {
  int N = matrix.size();
  int M = matrix[0].size();
  int low = 0;
  int high = M * N - 1;
  while (low <= high)
  {
   int mid = (low + (high - low) / 2);

   if (matrix[mid / M][mid % M] == target)
   {
    return true;
   }

   if (target > matrix[mid / M][mid % M])
   {
    low = mid + 1;
   }
   else
   {
    high = mid - 1;
   }
  }
  return false;
 }
};

/*
> Time Complexity: O(log2(n*m))
> Space Complexity: O(1)
*/

//! Approach 2

class Solution
{
public:
 bool searchMatrix(vector<vector<int>> &matrix, int target)
 {
  int M = matrix.size();
  int N = matrix[0].size();
  int row = 0, col = N - 1;
  // since we move left so j >= 0
  // since we move down so i < n
  while (row < M && col >= 0)
  {
   if (matrix[row][col] == target)
   {
    return 1;
   }

   if (target > matrix[row][col])
   {
    row++;
   }
   else
   {
    col--;
   }
  }
  return 0;
 }
};