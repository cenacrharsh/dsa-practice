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