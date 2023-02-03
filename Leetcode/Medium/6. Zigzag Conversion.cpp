#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=7dKiBCY-HmQ

class Solution
{
public:
 string convert(string s, int numRows)
 {
  if (numRows == 1)
   return s;
  string ans = "";
  int jumps = (numRows - 1) * 2;
  for (int i = 0; i < numRows; i++)
  {
   for (int j = i; j < s.size(); j += jumps)
   {
    ans += s[j];
    if ((i > 0) && (i < numRows - 1) && (j + (jumps - 2 * i) < s.size()))
    {
     ans += s[j + jumps - 2 * i];
    }
   }
  }
  return ans;
 }
};