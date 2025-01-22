#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
  {
    //* Multi Source BFS
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        //* 0 is land, 1 is water
        if (isWater[i][j] == 1)
        {
          height[i][j] = 0;
          q.push({i, j}); //* push all water cells into queue for multi source BFS
        }
      }
    }

    while (!q.empty())
    {
      auto [row, col] = q.front();
      q.pop();
      for (const auto &dir : directions)
      {
        int newRow = row + dir[0];
        int newCol = col + dir[1];

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && height[newRow][newCol] == -1)
        {
          height[newRow][newCol] = height[row][col] + 1;
          q.push({newRow, newCol});
        }
      }
    }

    return height;
  }
};