#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Unordered Map

class Solution
{
public:
 int countWords(vector<string> &words1, vector<string> &words2)
 {
  unordered_map<string, int> freq1;
  unordered_map<string, int> freq2;
  for (string i : words1)
  {
   freq1[i]++;
  }
  for (string i : words2)
  {
   freq2[i]++;
  }
  int count = 0;
  for (auto i : freq1)
  {
   if (freq2.find(i.first) != freq2.end() && i.second == 1 && freq2[i.first] == 1)
   {
    count++;
   }
  }
  return count;
 }
};