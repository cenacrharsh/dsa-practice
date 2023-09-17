#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#define ROWS 50
#define COLS 50

//! Approach 1

/*
> Time Complexity: O((n * m) + (n + m)) => O(n * m)
> Space Complexity: O(1)
*/

void makeAllZero(int mat[ROWS][COLS], int r, int c)
{
 int i, j;
 bool rowFlag = false, colFlag = false;
 // traversing 1st row
 for (i = 0; i < c; i++)
 {
  if (mat[0][i] == 0)
  {
   rowFlag = true;
  }
 }
 // traversing 1st col
 for (i = 0; i < r; i++)
 {
  if (mat[i][0] == 0)
  {
   colFlag = true;
  }
 }
 // traversing rest of array
 for (i = 1; i < r; i++)
 {
  for (j = 1; j < c; j++)
  {
   if (mat[i][j] == 0)
   {
    // mark row as 0
    mat[i][0] = 0;
    // mark col as 0
    mat[0][j] = 0;
   }
  }
 }
 // now mark aq to values stored in 1st row & col
 for (i = 1; i < r; i++)
 {
  for (j = 1; j < c; j++)
  {
   if (mat[i][0] == 0 || mat[0][j] == 0)
   {
    mat[i][j] = 0;
   }
  }
 }
 // 1st row 0 if rowFlag true
 if (rowFlag)
 {
  for (i = 0; i < c; i++)
  {
   mat[0][i] = 0;
  }
 }
 // 1st col 0 if colFlag true
 if (colFlag)
 {
  for (i = 0; i < c; i++)
  {
   mat[i][0] = 0;
  }
 }
}

//! Approach 2

/*
> Time Complexity: O(n * m)
> Space Complexity: O(n + m)
*/

void makeAllZero(int mat[ROWS][COLS], int n, int m)
{
 int i, j;
 int row[n], column[m];
 for (i = 0; i < n; i++)
 {
  row[i] = 1;
 }
 for (i = 0; i < m; i++)
 {
  column[i] = 1;
 }

 for (i = 0; i < n; i++)
 {
  for (j = 0; j < m; j++)
  {
   if (mat[i][j] == 0)
   {
    row[i] = 0;
    column[j] = 0;
   }
  }
 }

 for (i = 0; i < n; i++)
 {
  for (j = 0; j < m; j++)
  {
   if (row[i] == 0 || column[j] == 0)
   {
    mat[i][j] = 0;
   }
  }
 }
}