#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 pointers
class Solution
{
public:
 string reverseStr(string s, int k)
 {
  int n = s.size();
  for (int i = 0; i < n; i += 2 * k)
  {
   int start = i;
   int end = min(start + k - 1, n - 1); //* -1 because of 0-based indexing
   while (start < end)
   {
    swap(s[start], s[end]);
    start++;
    end--;
   }
  }
  return s;
 }
};