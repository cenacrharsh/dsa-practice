#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

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