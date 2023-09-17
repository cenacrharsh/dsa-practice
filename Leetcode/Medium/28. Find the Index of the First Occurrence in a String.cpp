#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Personal Solution
class Solution
{
public:
 int strStr(string haystack, string needle)
 {
  int n = haystack.size();
  int m = needle.size();
  int i = 0, j = 0, k = 0;
  while (j < n)
  {
   i = j;
   k = 0;
   if (haystack[j] == needle[k])
   {
    // cout << "found match at index: " << j << " and: " << k << endl;
    while (j < n && k < m && haystack[j] == needle[k])
    {
     j++;
     k++;
    }
    // cout << "match ending at index: " << j << " and: " << k << endl;
    if (k == m)
    {
     return i;
    }
    j = i;
   }
   j++;
  }
  return -1;
 }
};