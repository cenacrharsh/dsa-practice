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
 bool halvesAreAlike(string s)
 {
  unordered_map<char, int> freq1, freq2;
  int n = s.length();
  for (int i = 0; i < n / 2; i++)
  {
   freq1[s[i]]++;
  }
  for (int i = n / 2; i < n; i++)
  {
   freq2[s[i]]++;
  }
  int count1 = 0, count2 = 0;
  for (auto x : freq1)
  {
   char currChar = x.first;
   if (currChar == 'a' || currChar == 'e' || currChar == 'i' || currChar == 'o' || currChar == 'u' || currChar == 'A' || currChar == 'E' ||
       currChar == 'I' || currChar == 'O' || currChar == 'U')
   {
    count1 += freq1[currChar];
   }
  }
  for (auto x : freq2)
  {
   char currChar = x.first;
   if (currChar == 'a' || currChar == 'e' || currChar == 'i' || currChar == 'o' || currChar == 'u' || currChar == 'A' || currChar == 'E' ||
       currChar == 'I' || currChar == 'O' || currChar == 'U')
   {
    count2 += freq2[currChar];
   }
  }
  return (count1 == count2);
 }
};