#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

void findWays(int maze[][50], int size, int &totalWays, int r, int c)
{
 if (r == size - 1 && c == size - 1)
 {
  totalWays++;
  return;
 }

 if (c + 1 < size && maze[r][c + 1] != -1)
 {
  findWays(maze, size, totalWays, r, c + 1);
 }

 if (r + 1 < size && maze[r + 1][c] != -1)
 {
  findWays(maze, size, totalWays, r + 1, c);
 }
}

int solveMaze(int maze[][50], int size)
{
 // Write your code here
 int totalWays = 0;
 findWays(maze, size, totalWays, 0, 0);
 return totalWays;
}

int main()
{
 int sz, maze[50][50];
 cin >> sz;
 for (int i = 0; i < sz; i++)
  for (int j = 0; j < sz; j++)
   cin >> maze[i][j];

 int result = solveMaze(maze, sz);
 cout << result;
 return 0;
}