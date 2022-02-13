#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
 bool checkIfPangram(string sentence)
 {
  int freq[26] = {0};
  for (int i = 0; i < sentence.length(); i++)
  {
   freq[sentence[i] - 'a'] = 1;
  }
  bool ans = true;
  for (int i = 0; i < 26; i++)
  {
   if (freq[i] == 0)
   {
    ans = false;
   }
  }
  if (ans)
  {
   return true;
  }
  else
  {
   return false;
  }
 }
};