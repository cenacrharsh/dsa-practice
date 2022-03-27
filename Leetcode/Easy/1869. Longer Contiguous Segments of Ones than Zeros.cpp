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
 bool checkZeroOnes(string s)
 {
  int maxCount0 = 0;
  int maxCount1 = 0;
  int i = 0;
  while (i < s.size())
  {
   if (s[i] == '1')
   {
    int count = 0;
    while (i < s.size() && s[i] == '1')
    {
     i++;
     count++;
    }
    maxCount1 = max(maxCount1, count);
   }
   else if (s[i] == '0')
   {
    int count = 0;
    while (i < s.size() && s[i] == '0')
    {
     i++;
     count++;
    }
    maxCount0 = max(maxCount0, count);
   }
  }
  return maxCount1 > maxCount0;
 }
};