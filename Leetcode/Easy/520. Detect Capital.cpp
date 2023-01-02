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
 bool detectCapitalUse(string word)
 {
  int caps = 0;
  for (int i = 0; i < word.size(); i++)
  {
   if (isupper(word[i]))
   {
    caps++;
   }
  }
  if (caps == 0 || caps == word.size())
  {
   return true;
  }
  else if (caps == 1)
  {
   if (isupper(word[0]))
   {
    return true;
   }
  }
  return false;
 }
};