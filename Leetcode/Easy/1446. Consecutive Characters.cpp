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
 int maxPower(string s)
 {
  // Starting from the first char.
  int ans = 1, count = 1;
  for (int i = 1; i < s.size(); i++)
  {
   if (s[i] != s[i - 1])
   {
    count = 0;
   }
   count++;
   ans = max(ans, count);
  }
  return ans;
 }
};

class Solution
{
public:
 int maxPower(string s)
 {
  int maxCount = 1;
  int l = 0, r = 1;
  while (r < s.size())
  {
   if (s[l] == s[r])
   {
    while (r < s.size() && s[l] == s[r])
    {
     r++;
    }
    int tempCount = r - l;
    maxCount = max(maxCount, tempCount);
    l = r;
    r++;
    continue;
   }
   l++;
   r++;
  }
  return maxCount;
 }
};