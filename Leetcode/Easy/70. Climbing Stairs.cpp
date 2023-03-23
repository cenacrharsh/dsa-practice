#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Bottom Up Approach + Tabulation
class Solution
{
public:
 int climbStairs(int n)
 {
  if (n == 1)
  {
   return 1;
  }
  if (n == 2)
  {
   return 2;
  }
  vector<int> stairs(n + 1, 0);
  stairs[0] = 0;
  stairs[1] = 1; // one way to climb first stair
  stairs[2] = 2; // 2 ways to climb 2nd stair, 1 step or 2 step
  for (int i = 3; i <= n; i++)
  {
   stairs[i] = stairs[i - 1] + stairs[i - 2]; // since we can reach step n from step n-1 using 1 step and step n-2 using 2 steps, and we are calculating ways to actual steps taken, so reaching n-2th step in m ways then climbing to nth step in 2 steps also makes m ways to reach nth step
  }
  return stairs[n];
 }
};

//! Using Top Down Approach
class Solution
{
public:
 int climbStairs(int n)
 {
  int stairs[n + 1];
  stairs[n] = 1;     // already reached, can't jump
  stairs[n - 1] = 2; // only one possibility, edge case for when we are at one stair 1
  for (int i = n - 2; i >= 1; i--)
  {
   stairs[i] = stairs[i + 1] + stairs[i + 2];
  }
  for (int i = 1; i <= n; i++)
  {
   cout << stairs[i] << " ";
  }
  cout << endl;
  return stairs[1];
 }
};