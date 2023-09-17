#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#define N 10

void counterDiagonal(int mat[N][N], int n)
{
 // Write your code here
 for (int col = 0; col < n; col++)
 {
  for (int i = 0, j = col; j >= 0; i++, j--)
  {
   cout << mat[i][j] << " ";
  }
 }
 // traverse last col and print all counter diagonals starting from there
 for (int row = 1; row < n; row++)
 {
  for (int i = row, j = n - 1; i <= n - 1; i++, j--)
  {
   cout << mat[i][j] << " ";
  }
 }
}