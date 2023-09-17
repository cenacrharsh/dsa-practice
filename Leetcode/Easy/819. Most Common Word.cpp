#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=qbEtfHjAI8A (regex)

class Solution
{
public:
 string mostCommonWord(string paragraph, vector<string> &banned)
 {
  //* putting all words in banned into a set
  unordered_set<string> ban(banned.begin(), banned.end());

  //* converting all char in paragraph to lowercase, and converting all delimiters to ' '
  for (auto &ch : paragraph)
  {
   ch = isalpha(ch) ? tolower(ch) : ' ';
  }

  unordered_map<string, int> freq;
  string word = "";
  for (int i = 0; i < paragraph.size(); i++)
  {
   if (paragraph[i] != ' ')
   {
    while (i < paragraph.size() && paragraph[i] != ' ')
    {
     word += paragraph[i];
     i++;
    }
    freq[word]++;
    word = "";
   }
  }

  string ans;
  int max_freq = INT_MIN;
  for (auto i : freq)
  {
   if (i.second > max_freq && ban.find(i.first) == ban.end())
   {
    max_freq = i.second;
    ans = i.first;
   }
  }
  return ans;
 }
};