#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=t_f0nwwdg5o

//! Combination

/*
> Time Complexity: O(n-1) || O(m-1)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int uniquePaths(int m, int n)
 {
  // num of directions we have to choose from
  int N = m + n - 2; // m - 1 in right direction + n - 1 in down direction
  int R = m - 1;     // or n - 1; as m + n - 2 C m - 1 = m + n - 2 C n - 1

  // to calculate nCr = n * n - 1 * n - 2.. r times/1 * 2 * .. r times
  double res = 1;
  for (int i = 1; i <= R; i++)
  {
   res = res * (N - R + i) / i; // for 10C3 i gives 1 * 2 * 3, N - R + i (as N - R = 7, then 7 + i) gives 8 * 9 * 10
  }

  return (int)res;
 }
};

//! DP

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n*m)
*/

class Solution
{
public:
 int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp)
 {
  if (i >= m || j >= n)
   return 0;
  if (i == m - 1 && j == n - 1)
   return 1;

  if (dp[i][j] != -1)
  {
   return dp[i][j];
  }
  else
  {
   return dp[i][j] = countPaths(i + 1, j, m, n, dp) +
                     countPaths(i, j + 1, m, n, dp);
  }
 }
 int uniquePaths(int m, int n)
 {
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return countPaths(0, 0, m, n, dp);
 }
};

//! Brute Force Recursion

/*
> Time Complexity: O(2^n) => exponential
> Space Complexity: O(2^n)
*/

class Solution
{
public:
 int helper(int i, int j, int m, int n)
 {
  // when we reach destination
  if (i == m - 1 && j == n - 1)
   return 1;

  // if we go out of bounds
  if (i >= m || j >= n)
   return 0;

  // add the total ans from both paths avaiable
  return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
 }
 int uniquePaths(int m, int n)
 {
  return helper(0, 0, m, n);
 }
};