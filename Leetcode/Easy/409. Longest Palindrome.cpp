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
 int longestPalindrome(string s)
 {
  unordered_map<char, int> letter;
  for (auto c : s)
  {
   letter[c]++;
  }
  int ans = 0;
  for (auto it : letter)
  {
   ans += (it.second / 2) * 2;
   // now check if one unique char has been added or not
   // ans % 2 makes sure we only add it once
   // letter[i] % 2 checks if we have a leftover char of not
   if (ans % 2 == 0 && it.second % 2 == 1)
   {
    ans++;
   }
  }
  // if char left in s as ans < s.size(), means we got odd freq char
  // if(ans < s.size()) return ans + 1;
  // else return ans;
  return ans;
 }
};