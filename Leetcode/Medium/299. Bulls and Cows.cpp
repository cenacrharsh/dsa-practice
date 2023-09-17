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
 string getHint(string secret, string guess)
 {
  unordered_map<char, int> m; // map char to their indexes
  for (int i = 0; i < secret.size(); i++)
  {
   m[secret[i]]++;
  }
  string ans = "";
  int bull = 0, cow = 0;
  for (int i = 0; i < guess.size(); i++)
  {
   if (guess[i] == secret[i])
   {
    bull++;
    m[guess[i]]--;
    if (m[guess[i]] == 0)
    {
     m.erase(guess[i]);
    }
    guess[i] = '*';
   }
  }
  for (int i = 0; i < guess.size(); i++)
  {
   if (guess[i] != '*' && m.find(guess[i]) != m.end())
   {
    cow++;
    m[guess[i]]--;
    if (m[guess[i]] == 0)
    {
     m.erase(guess[i]);
    }
   }
  }
  ans = to_string(bull) + "A" + to_string(cow) + "B";
  return ans;
 }
};