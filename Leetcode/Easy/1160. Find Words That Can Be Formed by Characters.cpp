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
 int countCharacters(vector<string> &words, string chars)
 {
  vector<int> freq(26);
  for (char ch : chars)
  {
   freq[ch - 'a']++;
  }

  int ans = 0;
  for (string word : words)
  {
   vector<int> temp_freq = freq;
   bool possible = true;
   for (char ch : word)
   {
    if (temp_freq[ch - 'a'] != 0)
    {
     temp_freq[ch - 'a']--;
    }
    else
    {
     possible = false;
    }
   }
   if (possible)
   {
    ans += word.size();
   }
  }
  return ans;
 }
};