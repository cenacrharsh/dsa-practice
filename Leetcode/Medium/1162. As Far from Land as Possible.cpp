#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(n2)
> Space Complexity: O(n2)
*/

// # Tutorial: https://www.youtube.com/watch?v=HUce21um6VA

class Solution
{
 vector<int> dr = {0, 0, 1, -1};
 vector<int> dc = {1, -1, 0, 0};

public:
 bool isPos(int r, int c, int n)
 {
  return (r >= 0 && c >= 0 && r < n && c < n);
 }

 int maxDistance(vector<vector<int>> &grid)
 {
  int n = grid.size();
  vector<vector<int>> dist(n, vector<int>(n, -1));
  queue<vector<int>> pq;
  for (int i = 0; i < n; i++)
  {
   for (int j = 0; j < n; j++)
   {
    if (1 == grid[i][j])
    {
     dist[i][j] = 0;
     pq.push({i, j});
    }
   }
  }
  int ans = 0;
  while (!pq.empty())
  {
   vector<int> vect = pq.front();
   pq.pop();
   int r = vect[0];
   int c = vect[1];
   if (0 == grid[r][c])
   {
    ans = max(ans, dist[r][c]);
   }
   for (int i = 0; i < 4; i++)
   {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (isPos(nr, nc, n) && -1 == dist[nr][nc])
    {
     dist[nr][nc] = dist[r][c] + 1;
     pq.push({nr, nc});
    }
   }
  }
  return (ans == 0 ? -1 : ans);
 }
};

//! Leetcode Approach

class Solution
{
public:
 // Four directions: Up, Down, Left and Right.
 const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

 int maxDistance(vector<vector<int>> &grid)
 {
  // A copy matrix of the grid to mark water cells as land once visited.
  int visited[grid.size()][grid[0].size()];

  // Insert all the land cells in the queue.
  queue<pair<int, int>> q;
  for (int i = 0; i < grid.size(); i++)
  {
   for (int j = 0; j < grid[0].size(); j++)
   {
    // Copy grid to the visited matrix.
    visited[i][j] = grid[i][j];
    if (grid[i][j])
    {
     q.push({i, j});
    }
   }
  }

  int distance = -1;
  while (!q.empty())
  {
   int qSize = q.size();

   // Iterate over all the current cells in the queue.
   while (qSize--)
   {
    pair<int, int> landCell = q.front();
    q.pop();

    // From the current land cell, traverse to all the four directions
    // and check if it is a water cell. If yes, convert it to land
    // and add it to the queue.
    for (pair<int, int> dir : direction)
    {
     int x = landCell.first + dir.first;
     int y = landCell.second + dir.second;

     if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0)
     {
      // Marking as 1 to avoid re-iterating it.
      visited[x][y] = 1;
      q.push({x, y});
     }
    }
   }

   // After each iteration of queue elements, increment distance
   // as we covered 1 unit distance from all cells in every direction.
   distance++;
  }

  // If the distance is 0, there is no water cell.
  return distance == 0 ? -1 : distance;
 }
};