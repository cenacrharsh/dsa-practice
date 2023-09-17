#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=61BxjyZddVg

class Solution
{
public:
 unordered_map<char, int> characters;
 bool compare(string word1, string word2)
 {
  int len1 = word1.length(), len2 = word2.length();
  for (int i = 0; i < min(len1, len2); i++)
  {
   if (characters[word1[i]] < characters[word2[i]])
   {
    return true;
   }
   else if (characters[word1[i]] > characters[word2[i]])
   {
    return false;
   }
  }
  // if word2 = word1 + "...", then word2 > word1 because of extra characters
  if (len2 >= len1)
  {
   return true;
  }
  return false;
 }
 bool isAlienSorted(vector<string> &words, string order)
 {
  for (int i = 0; i < order.length(); i++)
  {
   characters[order[i]] = i;
  }
  for (int i = 0; i < words.size() - 1; i++)
  {
   if (!compare(words[i], words[i + 1]))
   {
    return false;
   }
  }
  return true;
 }
};