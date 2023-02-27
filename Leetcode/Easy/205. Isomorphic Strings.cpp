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
 bool isIsomorphic(string s, string t)
 {
  // check if number of unique characters is same
  unordered_set<char> freq1;
  for (auto it : s)
  {
   freq1.insert(it);
  }
  unordered_set<char> freq2;
  for (auto it : t)
  {
   freq2.insert(it);
  }
  if (freq1.size() != freq2.size())
  {
   return false;
  }

  unordered_map<char, char> m;
  for (int i = 0; i < s.size(); i++)
  {
   if (m.find(s[i]) != m.end())
   {
    if (m[s[i]] != t[i])
    {
     return false;
    }
   }
   else
   {
    m[s[i]] = t[i];
   }
  }
  return true;
 }
};