#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int N;

bool isSafe(int board[][10], int r, int c)
{
 int i, j;
 for (i = 0; i < r; i++)
 {
  if (board[i][c] == 1)
   return false;
 }

 i = r - 1;
 j = c - 1;
 while (i >= 0 && j >= 0)
 {
  if (board[i][j] == 1)
   return false;
  i--;
  j--;
 }

 i = r - 1;
 j = c + 1;
 while (i >= 0 && j < N)
 {
  if (board[i][j] == 1)
   return false;
  i--;
  j++;
 }

 return true;
}

bool solveNQUtil(int board[][10], int r, int sol[][10], int *nos)
{
 if (r == N)
 {
  int k = 0, x = *nos;
  for (int i = 0; i < N; i++)
  {
   for (int j = 0; j < N; j++)
   {
    if (board[i][j] == 1)
    {
     sol[x][k++] = j;
    }
   }
  }
  x++;
  *nos = x;
  return true;
 }

 bool res = false;

 for (int j = 0; j < N; j++)
 {
  if (isSafe(board, r, j))
  {
   board[r][j] = 1;
   res = solveNQUtil(board, r + 1, sol, nos) || res;
   board[r][j] = 0;
  }
 }
 return res;
}

//! normal code

#include <iostream>
using namespace std;

#define n 4

bool isSafe(int board[n][n], int r, int c)
{
 int i, j;
 for (i = 0; i < r; i++)
 {
  if (board[i][c] == 1)
   return false;
 }

 i = r - 1;
 j = c - 1;
 while (i >= 0 && j >= 0)
 {
  if (board[i][j] == 1)
   return false;
  i--;
  j--;
 }
 i = r - 1;
 j = c + 1;
 while (i >= 0 && j < n)
 {
  if (board[i][j] == 1)
   return false;
  i--;
  j++;
 }
 return true;
}
bool solveNQueen(int board[n][n], int r)
{
 if (r == n)
  return true;

 for (int j = 0; j < n; j++)
 {
  if (isSafe(board, r, j))
  {
   board[r][j] = 1;
   if (solveNQueen(board, r + 1))
    return true;
   board[r][j] = 0;
  }
 }
 return false;
}
void printSolution(int board[n][n])
{
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
   cout << " " << board[i][j] << " ";
  cout << endl;
 }
}
int main()
{
 int board[n][n] = {0};

 if (solveNQueen(board, 0))
 {
  printSolution(board);
 }
 return 0;
}

//! Optimized code

/*
The idea is when we try placing a queen at (i, j) position, then

For checking a queen in the jth column we should not iterate the whole column rather we maintain a boolean array column[] for the lookup in O(1) time.

> Similarly, we need not check every element in right and left diagonal instead use the property of diagonals:

* The sum of i and j is constant and unique for each right diagonal, therefore we’ll use a boolean array rd[] for the lookup along the right diagonal.

* The difference of i and j is constant and unique for each left diagonal, therefore we’ll use a boolean array ld[] for the lookup.
*/

#include <iostream>
using namespace std;

#define n 4

int col[n] = {0};
int ld[2 * n] = {0};
int rd[2 * n] = {0};

bool isSafe(int r, int c)
{
 if (col[c] == 1 || ld[r - c + n - 1] == 1 || rd[r + c] == 1)
  return false;

 return true;
}
bool solveNQueen(int board[n][n], int r)
{
 if (r == n)
  return true;

 for (int j = 0; j < n; j++)
 {
  if (isSafe(r, j))
  {
   board[r][j] = 1;
   col[j] = 1;
   ld[r - j + n - 1] = 1;
   rd[r + j] = 1;
   if (solveNQueen(board, r + 1))
    return true;
   board[r][j] = 0;
   col[j] = 0;
   ld[r - j + n - 1] = 0;
   rd[r + j] = 0;
  }
 }
 return false;
}
void printSolution(int board[n][n])
{
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < n; j++)
   cout << " " << board[i][j] << " ";
  cout << endl;
 }
}
int main()
{
 int board[n][n] = {0};

 if (solveNQueen(board, 0))
  printSolution(board);
 else
  cout << "Solution does not exist";

 return 0;
}
