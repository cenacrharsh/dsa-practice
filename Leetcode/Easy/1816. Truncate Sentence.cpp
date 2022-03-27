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
 string truncateSentence(string s, int k)
 {
  string ans = "";
  string word = "";
  int count = 0;
  for (int i = 0; i < s.size(); i++)
  {
   if (s[i] != ' ')
   {
    while (i < s.size() && s[i] != ' ')
    {
     word += s[i];
     i++;
    }
    ans = ans + word;
    word = "";
    count++;
    if (count == k)
    {
     break;
    }
    else
    {
     ans += " ";
    }
   }
  }

  return ans;
 }
};