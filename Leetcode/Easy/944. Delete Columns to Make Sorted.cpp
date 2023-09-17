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
 int minDeletionSize(vector<string> &strs)
 {
  int wordLen = strs[0].size();
  int count = 0;
  for (int i = 0; i < wordLen; i++)
  {
   for (int j = 1; j < strs.size(); j++)
   {
    string currWord = strs[j];
    string prevWord = strs[j - 1];
    if (currWord[i] < prevWord[i])
    {
     count++;
     break;
    }
   }
  }
  return count;
 }
};