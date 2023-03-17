#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=FWAIf_EVUKE
class Solution
{
public:
 void solveSudoku(vector<vector<char>> &board)
 {
  solve(board);
 }

 bool isValid(vector<vector<char>> &board, int row, int col, char c)
 {
  for (int i = 0; i < 9; i++)
  {
   // check in all the rows
   if (board[i][col] == c)
    return false;

   // check in all the columns
   if (board[row][i] == c)
    return false;

   // check in the current block
   if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
    return false;
  }
  return true;
 }

 bool solve(vector<vector<char>> &board)
 {
  for (int i = 0; i < board.size(); i++)
  {
   for (int j = 0; j < board[0].size(); j++)
   {
    if (board[i][j] == '.')
    {
     for (char c = '1'; c <= '9'; c++)
     {
      if (isValid(board, i, j, c))
      {
       board[i][j] = c;

       // backtracking
       if (solve(board))
        return true;
       else
        board[i][j] = '.';
      }
     }

     return false;
    }
   }
  }
  return true;
 }
};