#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 2 loops

class Solution
{
public:
    bool isInside(int currRow, int currCol, int rows, int cols)
    {
        if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols)
        {
            return true;
        }
        return false;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int moves = 1;
        int dir = 0;
        int row = rStart, col = cStart;
        while (ans.size() < rows * cols)
        {
            //* after every 2 iteration the moves increase by 1
            for (int i = 0; i < 2; i++)
            {
                int delRow = directions[dir][0], delCol = directions[dir][1];
                for (int j = 0; j < moves; j++)
                {
                    if (isInside(row, col, rows, cols))
                    {
                        ans.push_back({row, col});
                    }
                    row = row + delRow;
                    col = col + delCol;
                }
                dir = (dir + 1) % 4; //* after 0, 1, 2, 3 we want to go back to 1
            }
            moves++;
        }
        return ans;
    }
};

//! 4 Loops

class Solution
{
public:
    bool isInside(int currRow, int currCol, int rows, int cols)
    {
        if (currRow >= 0 && currRow < rows && currCol >= 0 && currCol < cols)
        {
            return true;
        }
        return false;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int moves = 1, direction = 0;
        vector<vector<int>> ans;
        int row = rStart, col = cStart;
        while (ans.size() < rows * cols)
        {
            if (direction == 0)
            {
                for (int i = 1; i <= moves; i++)
                {
                    if (isInside(row, col, rows, cols))
                    {
                        ans.push_back({row, col});
                    }
                    col++;
                }
                direction = 1;
            }
            else if (direction == 1)
            {
                for (int i = 1; i <= moves; i++)
                {
                    if (isInside(row, col, rows, cols))
                    {
                        ans.push_back({row, col});
                    }
                    row++;
                }
                direction = 2;
                moves++;
            }
            else if (direction == 2)
            {
                for (int i = 1; i <= moves; i++)
                {
                    if (isInside(row, col, rows, cols))
                    {
                        ans.push_back({row, col});
                    }
                    col--;
                }
                direction = 3;
            }
            else if (direction == 3)
            {
                for (int i = 1; i <= moves; i++)
                {
                    if (isInside(row, col, rows, cols))
                    {
                        ans.push_back({row, col});
                    }
                    row--;
                }
                direction = 0;
                moves++;
            }
        }
        return ans;
    }
};