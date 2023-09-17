#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! 1 array
class Solution
{
public:
 bool isAnagram(string s, string t)
 {
  vector<int> freq(26, 0);
  for (int i = 0; i < s.size(); i++)
  {
   freq[s[i] - 'a']++;
  }
  for (int i = 0; i < t.size(); i++)
  {
   freq[t[i] - 'a']--;
  }
  for (int i = 0; i < 26; i++)
  {
   if (freq[i] != 0)
   {
    return false;
   }
  }
  return true;
 }
};

//! 2 arrays
class Solution
{
public:
 bool isAnagram(string s, string t)
 {
  int freq1[26] = {0};
  int freq2[26] = {0};

  for (int i = 0; i < s.length(); i++)
  {
   freq1[s[i] - 'a']++;
  }

  for (int i = 0; i < t.length(); i++)
  {
   freq2[t[i] - 'a']++;
  }

  bool ans = true;
  for (int i = 0; i < 26; i++)
  {
   if (freq1[i] != freq2[i])
   {
    ans = false;
   }
  }

  if (ans)
  {
   return true;
  }
  else
  {
   return false;
  }
 }
};