#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
 int helper(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
 {
  if (index == satisfaction.size())
   return 0;

  if (dp[index][time] != -1)
   return dp[index][time];

  int makeDish = (satisfaction[index] * time) +
                 helper(satisfaction, index + 1, time + 1, dp);
  int notMakeDish = 0 + helper(satisfaction, index + 1, time, dp);

  return dp[index][time] = max(makeDish, notMakeDish);
 }
 int maxSatisfaction(vector<int> &satisfaction)
 {
  int n = satisfaction.size();
  sort(satisfaction.begin(), satisfaction.end());
  vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
  for (int i = n - 1; i >= 0; i--)
  {
   for (int j = n; j >= 1; j--)
   {
    int makeDish = (satisfaction[i] * j) + dp[i + 1][j + 1];
    int notMakeDish = 0 + dp[i + 1][j];
    dp[i][j] = max(makeDish, notMakeDish);
   }
  }
  return dp[0][1];
 }
};

//! Memoization DP
class Solution
{
public:
 int helper(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
 {
  if (index == satisfaction.size())
   return 0;

  if (dp[index][time] != -1)
   return dp[index][time];

  int makeDish = (satisfaction[index] * time) +
                 helper(satisfaction, index + 1, time + 1, dp);
  int notMakeDish = 0 + helper(satisfaction, index + 1, time, dp);

  return dp[index][time] = max(makeDish, notMakeDish);
 }
 int maxSatisfaction(vector<int> &satisfaction)
 {
  int n = satisfaction.size();
  sort(satisfaction.begin(), satisfaction.end());
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  return helper(satisfaction, 0, 1, dp);
 }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
 int helper(vector<int> &satisfaction, int index, int time)
 {
  if (index == satisfaction.size())
   return 0;

  int makeDish = (satisfaction[index] * time) +
                 helper(satisfaction, index + 1, time + 1);
  int notMakeDish = 0 + helper(satisfaction, index + 1, time);

  return max(makeDish, notMakeDish);
 }
 int maxSatisfaction(vector<int> &satisfaction)
 {
  int n = satisfaction.size();
  sort(satisfaction.begin(), satisfaction.end());
  return helper(satisfaction, 0, 1);
 }
};