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
 vector<string> commonChars(vector<string> &words)
 {
  vector<int> min_freq(26, INT_MAX); // default value INT_MAX
  for (string current_word : words)
  {
   vector<int> temp_char_freq(26, 0);
   for (char current_char : current_word)
   {
    temp_char_freq[current_char - 'a']++;
   }

   for (int i = 0; i < 26; i++)
   {
    min_freq[i] = min(min_freq[i], temp_char_freq[i]);
   }
  }
  vector<string> ans;
  for (int i = 0; i < 26; i++)
  {
   while (min_freq[i] > 0)
   {
    // char ch = char(i + 'a');
    // string str = string(1, ch);
    ans.push_back(string(1, i + 'a'));
    min_freq[i]--;
   }
  }
  return ans;
 }
};