#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Backtracking

class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<int>>& visited, int currRow, int currCol, int row, int col) {
        if(currRow < 0 || currRow >= row || currCol < 0 || currCol >= col || grid[currRow][currCol] == 0 || visited[currRow][currCol] != 0) {
            return 0;
        }

        visited[currRow][currCol] = 1;

        int up = helper(grid, visited, currRow - 1, currCol, row, col);
        int right = helper(grid, visited, currRow, currCol + 1, row, col);
        int down = helper(grid, visited, currRow + 1, currCol, row, col);
        int left = helper(grid, visited, currRow, currCol - 1, row, col);

        visited[currRow][currCol] = 0;

        return grid[currRow][currCol] + max(max(up, right), max(down, left));
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int maxGold = 0;
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] != 0) {
                    int gold = helper(grid, visited, i, j, row, col);
                    maxGold = max(maxGold, gold);
                }
            }
        }
        return maxGold;
    }
};