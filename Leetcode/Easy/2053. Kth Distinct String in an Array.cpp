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
 string kthDistinct(vector<string> &arr, int k)
 {
  unordered_map<string, int> freq;
  for (string s : arr)
  {
   freq[s]++;
  }
  int count = 0;
  string ans = "";
  for (string s : arr)
  {
   if (freq[s] == 1)
   {
    count++;
    if (count == k)
    {
     ans = s;
     break;
    }
   }
  }
  return ans;
 }
};