#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://leetcode.com/problems/longest-common-subsequence/

//! Brute Force - Exponential Time Complexity

class Solution
{
public:
 int f(int i, int j, string &text1, string &text2)
 {
  if (i < 0 || j < 0)
  {
   return 0;
  }
  if (text1[i] == text2[j])
  {
   return 1 + f(i - 1, j - 1, text1, text2);
  }
  return max(f(i - 1, j, text1, text2), f(i, j - 1, text1, text2));
 }

 int longestCommonSubsequence(string text1, string text2)
 {
  int n = text1.size();
  int m = text2.size();
  return f(n - 1, m - 1, text1, text2);
 }
};

//! Memoization | Top Down DP

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n*m) + O(n+m) => n+m in auxiliary stack space (max depth of recursion tree in n+m)
*/

class Solution
{
public:
 int f(int i, int j, string &text1, string &text2, vector<vector<int>> &dp)
 {
  if (i < 0 || j < 0)
  {
   return 0;
  }
  if (dp[i][j] != -1)
  {
   return dp[i][j];
  }
  if (text1[i] == text2[j])
  {
   return dp[i][j] = 1 + f(i - 1, j - 1, text1, text2, dp);
  }
  return dp[i][j] = max(f(i - 1, j, text1, text2, dp), f(i, j - 1, text1, text2, dp));
 }

 int longestCommonSubsequence(string text1, string text2)
 {
  int n = text1.size();
  int m = text2.size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  return f(n - 1, m - 1, text1, text2, dp);
 }
};

//! Tabulation | Bottom Up DP

/*
> Time Complexity: O(n*m)
> Space Complexity: O(n+m)
*/

//* Using 2D array
class Solution
{
public:
 int longestCommonSubsequence(string text1, string text2)
 {
  int n = text1.size();
  int m = text2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  // shifting one index so now f(i, j) => f(text1[0...i-1], text2[0...j-1])
  // also f(0,j) | f(i, 0) = 0 now, since 0 indicates -1 now
  for (int i = 0; i <= n; i++)
  {
   dp[i][0] = 0;
  }
  for (int j = 0; j <= m; j++)
  {
   dp[0][j] = 0;
  }
  for (int i = 1; i <= n; i++)
  {
   for (int j = 1; j <= m; j++)
   {
    if (text1[i - 1] == text2[j - 1])
    {
     dp[i][j] = 1 + dp[i - 1][j - 1];
    }
    else
    {
     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
   }
  }
  return dp[n][m];
 }
};

//* Using 1D array
class Solution
{
public:
 int longestCommonSubsequence(string text1, string text2)
 {
  int n = text1.size();
  int m = text2.size();
  vector<int> curr(m + 1, 0), prev(m + 1, 0);
  for (int i = 1; i <= n; i++)
  {
   for (int j = 1; j <= m; j++)
   {
    if (text1[i - 1] == text2[j - 1])
    {
     curr[j] = 1 + prev[j - 1];
    }
    else
    {
     curr[j] = max(prev[j], curr[j - 1]);
    }
   }
   prev = curr;
  }
  return prev[m];
 }
};