#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=luCn7p2CIbI

class Solution
{
public:
 string smallestSubsequence(string s)
 {
  int freq[26] = {0};
  int visited[26] = {0};
  for (int i = 0; i < s.length(); i++)
  {
   freq[s[i] - 'a']++;
  }
  stack<char> unique;
  for (int i = 0; i < s.length(); i++)
  {
   // decrease the count of character
   freq[s[i] - 'a']--;

   // we check if char is already visited/added to stack
   if (visited[s[i] - 'a'])
   {
    continue;
   }

   // check if s[i] > or < than top of stack, remove elements from stack if > s[i] & their count > 0
   while (unique.size() > 0 && unique.top() > s[i] && freq[unique.top() - 'a'] > 0)
   {
    visited[unique.top() - 'a'] = 0;
    unique.pop();
   }
   unique.push(s[i]);
   visited[s[i] - 'a'] = 1;
  }

  string ans = "";

  while (unique.size() > 0)
  {
   ans = unique.top() + ans;
   unique.pop();
  }

  return ans;
 }
};