#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! BIT Manipulation ( using a ^ a = 0 )

class Solution
{
public:
 char findTheDifference(string s, string t)
 {
  char c = 0;
  for (char cs : s)
   c ^= cs;
  for (char ct : t)
   c ^= ct;
  return c;
 }
};

//! ASCII ( using ch - ch = 0 )

class Solution
{
public:
 char findTheDifference(string s, string t)
 {
  char c = 0;
  for (char ch : t)
  {
   c += ch;
  }
  for (char ch : s)
  {
   c -= ch;
  }
  return c;
  // int ans = 0;
  // for (auto &x : t)
  //  ans += x; // int+char=>int+ASCII of char
  // for (auto &x : s)
  //  ans -= x;
  // return char(ans); // converting ASCII to char
 }
};

//! Freq Array

class Solution
{
public:
 char findTheDifference(string s, string t)
 {
  vector<int> freq(26);
  char ans;
  for (int i = 0; i < s.size(); i++)
  {
   freq[s[i] - 'a']++;
  }
  for (int i = 0; i < t.size(); i++)
  {
   if (freq[t[i] - 'a'] == 0)
   {
    ans = t[i];
   }
   freq[t[i] - 'a']--;
  }
  return ans;
 }
};
