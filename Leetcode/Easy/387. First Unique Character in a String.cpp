#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Unordered Map

class Solution
{
public:
 int firstUniqChar(string s)
 {
  unordered_map<char, int> freq;
  for (int i = 0; i < s.size(); i++)
  {
   freq[s[i]]++;
  }
  for (int i = 0; i < s.size(); i++)
  {
   if (freq[s[i]] == 1)
   {
    return i;
   }
  }
  return -1;
 }
};