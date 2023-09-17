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
 vector<vector<int>> generateMatrix(int n)
 {
  int top = 0, down = n - 1, left = 0, right = n - 1;
  int dir = 0;
  int val = 1;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  while (top <= down && left <= right)
  {
   if (dir == 0)
   {
    for (int i = top; i <= right; i++)
    {
     matrix[top][i] = val++;
    }
    top++;
    dir = 1;
   }
   else if (dir == 1)
   {
    for (int i = top; i <= down; i++)
    {
     matrix[i][right] = val++;
    }
    right--;
    dir = 2;
   }
   else if (dir == 2)
   {
    for (int i = right; i >= left; i--)
    {
     matrix[down][i] = val++;
    }
    down--;
    dir = 3;
   }
   else if (dir == 3)
   {
    for (int i = down; i >= top; i--)
    {
     matrix[i][left] = val++;
    }
    left++;
    dir = 0;
   }
  }
  return matrix;
 }
};