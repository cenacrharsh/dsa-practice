#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=yf3oUhkvqA0&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9

/*
> Time Complexity: O(N * M) + O(N * M * 4)
> Space Complexity: O(N * M) + O(N * M)
*/

//- BFS - we want to rotten all oranges at equal distance simultaneously which is only possible with bfs

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> nodesLeft; // {{row, col}, time}
        int visited[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    nodesLeft.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
            }
        }

        int maxTime = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (!nodesLeft.empty())
        {
            int r = nodesLeft.front().first.first;
            int c = nodesLeft.front().first.second;
            int t = nodesLeft.front().second;
            maxTime = max(maxTime, t);
            nodesLeft.pop();

            //* traverse all 4 directions
            for (int i = 0; i < 4; i++)
            {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] != 2 && grid[nRow][nCol] == 1)
                {
                    nodesLeft.push({{nRow, nCol}, t + 1});
                    visited[nRow][nCol] = 2;
                }
            }
        }

        //* check if all fresh oranges have been converted
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return maxTime;
    }
};