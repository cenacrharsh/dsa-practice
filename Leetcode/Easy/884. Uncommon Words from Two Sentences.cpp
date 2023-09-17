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
 vector<string> uncommonFromSentences(string s1, string s2)
 {
  unordered_map<string, int> freq1;
  unordered_map<string, int> freq2;
  string word = "";
  for (int i = 0; i < s1.size(); i++)
  {
   if (s1[i] == ' ')
   {
    freq1[word]++;
    word = "";
   }
   else
   {
    word += s1[i];
   }
  }
  freq1[word]++;
  word = "";
  for (int i = 0; i < s2.size(); i++)
  {
   if (s2[i] == ' ')
   {
    freq2[word]++;
    word = "";
   }
   else
   {
    word += s2[i];
   }
  }
  freq2[word]++;
  vector<string> ans;
  for (auto i : freq1)
  {
   if (i.second == 1 && freq2.find(i.first) == freq2.end())
   {
    ans.push_back(i.first);
   }
  }
  for (auto i : freq2)
  {
   if (i.second == 1 && freq1.find(i.first) == freq1.end())
   {
    ans.push_back(i.first);
   }
  }
  return ans;
 }
};