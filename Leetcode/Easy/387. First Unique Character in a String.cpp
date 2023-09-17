#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Freq Array

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
 int firstUniqChar(string s)
 {
  vector<int> freq(26);
  for (int i = 0; i < s.size(); i++)
  {
   freq[s[i] - 'a']++;
  }
  for (int i = 0; i < s.size(); i++)
  {
   if (freq[s[i] - 'a'] == 1)
   {
    return i;
   }
  }
  return -1;
 }
};

//! Using Unordered Map

/*
> Time Complexity: O(n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 int firstUniqChar(string s)
 {
  unordered_map<char, int> freq;
  for (int i = 0; i < s.size(); i++)
  {
   freq[s[i]]++;
  }
  for (int i = 0; i < s.size(); i++)
  {
   if (freq[s[i]] == 1)
   {
    return i;
   }
  }
  return -1;
 }
};