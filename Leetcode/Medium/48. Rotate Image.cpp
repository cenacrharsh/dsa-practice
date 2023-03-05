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
 void rotate(vector<vector<int>> &matrix)
 {
  int n = matrix.size();
  int m = matrix[0].size();
  //* transposing the matrix
  for (int i = 0; i < n; i++)
  {
   // using j = i+1 since we can skip diagonal elements and since we only need to swap elements above the diagonal
   for (int j = i + 1; j < m; j++)
   {
    swap(matrix[i][j], matrix[j][i]);
   }
  }

  //* reversing the columns
  for (int i = 0; i < n; i++)
  {
   int l = 0;
   int r = m - 1;
   while (l <= r)
   {
    swap(matrix[i][l], matrix[i][r]);
    l++;
    r--;
   }
   //> or
   // for(int j = 0; j < m/2; j++)
   // {
   //     swap(matrix[i][j], matrix[i][m-1-j]);
   // }
  }
 }
};