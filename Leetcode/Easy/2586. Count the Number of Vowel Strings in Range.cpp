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
 int vowelStrings(vector<string> &words, int left, int right)
 {
  int ans = 0;
  for (int i = left; i <= right; i++)
  {
   string currWord = words[i];
   if (currWord[0] == 'a' || currWord[0] == 'e' || currWord[0] == 'i' || currWord[0] == 'o' || currWord[0] == 'u')
   {
    int len = currWord.size();
    if (currWord[len - 1] == 'a' || currWord[len - 1] == 'e' || currWord[len - 1] == 'i' || currWord[len - 1] == 'o' || currWord[len - 1] == 'u')
    {
     ans++;
    }
   }
  }
  return ans;
 }
};