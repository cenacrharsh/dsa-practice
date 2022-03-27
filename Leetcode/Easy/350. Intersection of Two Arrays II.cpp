#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Map

class Solution
{
public:
 vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
 {
  map<int, int> freq1;
  map<int, int> freq2;
  for (int i : nums1)
  {
   freq1[i]++;
  }
  for (int i : nums2)
  {
   freq2[i]++;
  }
  vector<int> ans;
  for (auto i : freq1)
  {
   if (freq2.find(i.first) != freq2.end())
   {
    int count1 = i.second;
    int count2 = freq2[i.first];
    int count = min(count1, count2);
    while (count--)
    {
     ans.push_back(i.first);
    }
   }
  }
  return ans;
 }
};