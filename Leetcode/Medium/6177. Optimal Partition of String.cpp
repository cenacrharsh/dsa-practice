#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution
class Solution
{
public:
 int partitionString(string s)
 {
  int count = 0;
  for (int i = 0; i <= s.length() - 1; i++)
  {
   bool unique = true;
   int freq[26] = {0};
   while (unique && (i <= s.length() - 1))
   {
    if (freq[s[i] - 'a'] == 0)
    {
     freq[s[i] - 'a']++;
     i++;
    }
    else
    {
     count++;
     i--;
     unique = false;
    }
   }
  }
  return ++count;
 }
};