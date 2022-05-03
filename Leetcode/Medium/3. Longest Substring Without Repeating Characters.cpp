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
 int lengthOfLongestSubstring(string s)
 {
  if (s == "")
  {
   return 0;
  }
  unordered_set<int> unique;
  int len = 0, maxLen = INT_MIN;
  int l = 0, r = 0;
  while (r < s.size())
  {
   if (unique.find(s[r]) != unique.end())
   {
    while (unique.find(s[r]) != unique.end())
    {
     unique.erase(s[l]);
     l++;
    }
   }
   unique.insert(s[r]);
   len = r - l + 1;
   maxLen = max(maxLen, len);
   r++;
  }
  return maxLen;
 }
};