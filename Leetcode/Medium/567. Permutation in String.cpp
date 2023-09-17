#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=3zSSJvrXMG0

class Solution
{
public:
 bool checkInclusion(string s1, string s2)
 {
  unordered_map<char, int> freq;
  for (auto it : s1)
  {
   freq[it]++;
  }
  int i = 0, j = 0;
  int count = freq.size(); // count of unique char in s
  int len = s1.size();
  while (j < s2.size())
  {
   if (freq.find(s2[j]) != freq.end())
   {
    freq[s2[j]]--;
    if (freq[s2[j]] == 0)
    {
     count--;
    }
   }

   int sizeOfWindow = j - i + 1;
   if (sizeOfWindow < len)
   {
    j++;
   }
   else if (sizeOfWindow == len)
   {
    if (count == 0)
    {
     return true;
    }

    if (freq.find(s2[i]) != freq.end())
    {
     freq[s2[i]]++;
     if (freq[s2[i]] == 1)
     {
      count++;
     }
    }
    i++;
    j++;
   }
  }
  return false;
 }
};