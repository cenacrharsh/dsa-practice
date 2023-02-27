#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 2 pointer
class Solution
{
public:
 bool isSubsequence(string s, string t)
 {
  int i = 0;
  int j = 0;
  int n = s.size();
  int m = t.size();
  while (i < n && j < m)
  {
   if (s[i] == t[j])
   {
    i++;
   }
   j++;
  }
  if (i == n)
  {
   return true;
  }
  else
  {
   return false;
  }
 }
};

//! Recursion
class Solution
{
public:
 int f(string &s, string &t, int i, int j)
 {
  if (i < 0 || j < 0)
  {
   return 0;
  }

  if (s[i] == t[j])
  {
   return 1 + f(s, t, i - 1, j - 1);
  }
  return f(s, t, i, j - 1);
 }
 bool isSubsequence(string s, string t)
 {
  int l1 = s.size();
  int l2 = t.size();

  if (l1 > l2)
   return false;

  if (f(s, t, l1 - 1, l2 - 1) == l1)
   return true;
  else
   return false;
 }
};