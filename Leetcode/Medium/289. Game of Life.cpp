#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! inplace

class Solution
{
public:
 void gameOfLife(vector<vector<int>> &board)
 {
  vector<vector<int>> dir{
      {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
  int r = board.size(), c = board[0].size();
  for (int i = 0; i < r; i++)
  {
   for (int j = 0; j < c; j++)
   {
    int live = 0;
    for (auto d : dir)
    {
     int p = i + d[0];
     int q = j + d[1];

     if (p >= 0 && p < r && q >= 0 && q < c && (board[p][q] == 1 || board[p][q] == 2))
     {
      live++;
     }
    }

    if (board[i][j] == 1)
    {
     // 2: alive->dead
     if (live < 2)
     {
      board[i][j] = 2;
     }
     else if (live == 2 || live == 3)
     {
      continue;
     }
     else if (live > 3)
     {
      board[i][j] = 2;
     }
    }
    else if (board[i][j] == 0)
    {
     // 3: dead->alive
     if (live == 3)
     {
      board[i][j] = 3;
     }
    }
   }
  }
  for (int i = 0; i < r; i++)
  {
   for (int j = 0; j < c; j++)
   {
    board[i][j] %= 2; // 2 % 2 = 0, 1 % 2 or 3 % 2 = 1
   }
  }
 }
};

//! temp array

/*
> Time Complexity: O(n * m)
> Space Complexity: O(n * m)
*/

class Solution
{
public:
 void gameOfLife(vector<vector<int>> &board)
 {
  vector<vector<int>> dir{
      {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
  int r = board.size(), c = board[0].size();
  vector<vector<int>> temp(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++)
  {
   for (int j = 0; j < c; j++)
   {
    int live = 0;
    for (auto d : dir)
    {
     int p = i + d[0];
     int q = j + d[1];

     if (p >= 0 && p < r && q >= 0 && q < c && board[p][q] == 1)
     {
      live++;
     }
    }

    temp[i][j] = board[i][j];
    if (board[i][j] == 1)
    {
     if (live < 2)
     {
      temp[i][j] = 0;
     }
     else if (live == 2 || live == 3)
     {
      continue;
     }
     else if (live > 3)
     {
      temp[i][j] = 0;
     }
    }
    else if (board[i][j] == 0)
    {
     if (live == 3)
     {
      temp[i][j] = 1;
     }
    }
   }
  }
  board = temp;
 }
};