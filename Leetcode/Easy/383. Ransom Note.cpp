#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Freq Arary

class Solution
{
public:
 bool canConstruct(string ransomNote, string magazine)
 {
  vector<int> freq(26);
  for (char ch : magazine)
  {
   freq[ch - 'a']++;
  }
  for (char ch : ransomNote)
  {
   if (freq[ch - 'a'] == 0)
   {
    return false;
   }
   freq[ch - 'a']--;
  }
  return true;
 }
};