#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution

class Solution
{
public:
 int countPrefixes(vector<string> &words, string s)
 {
  int count = 0;
  for (int i = 0; i < words.size(); i++)
  {
   string currWord = words[i];
   bool flag = true;
   for (int j = 0; j < currWord.size(); j++)
   {
    if (s[j] != currWord[j])
    {
     flag = false;
    }
   }
   if (flag)
   {
    count++;
   }
  }
  return count;
 }
};