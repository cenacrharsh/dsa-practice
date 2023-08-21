#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=7zmgQSJghpo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11

/*
> Time Complexity: O(n * m * log(n * m)) + O(n * m * 4) => for loop + dfs
> Space Complexity: O(n * m)
*/

int dfs(int row, int col, vector<vector<int>> &visited,
        int **grid, vector<pair<int, int>> &temp,
        int row0, int col0, int n, int m)
{
    visited[row][col] = 1;
    temp.push_back({row - row0, col - col0});
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, visited, grid, temp, row0, col0, n, m);
        }
    }
}

int distinctIslands(int **grid, int n, int m)
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> temp;
                dfs(i, j, visited, grid, temp, i, j, n, m);
                st.insert(temp);
            }
        }
    }
    return st.size();
}