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
 string reverseWords(string s)
 {
  string res = "";
  vector<string> rev;
  for (int i = 0; i < s.size(); i++)
  {
   if (s[i] != ' ')
   {
    res += s[i];
   }
   else
   {
    if (!res.empty())
    {
     rev.push_back(res);
    }
    res = "";
   }
  }
  if (!res.empty())
  {
   rev.push_back(res);
  }
  res = "";
  for (int i = rev.size() - 1; i >= 0; i--)
  {
   res = res + rev[i] + " ";
  }
  res.pop_back();
  return res;
 }
};