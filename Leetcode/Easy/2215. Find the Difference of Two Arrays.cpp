#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Unordered Set

class Solution
{
public:
 vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
 {
  vector<vector<int>> ans(2);
  unordered_set<int> freq1(begin(nums1), end(nums1));
  unordered_set<int> freq2(begin(nums2), end(nums2));
  for (auto i : freq1)
  {
   if (freq2.find(i) == freq2.end())
   {
    ans[0].push_back(i);
   }
  }
  for (auto i : freq2)
  {
   if (freq1.find(i) == freq2.end())
   {
    ans[1].push_back(i);
   }
  }
  return ans;
 }
};

//! Unordered Map

class Solution
{
public:
 vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
 {
  vector<vector<int>> ans(2);
  unordered_map<int, int> freq1;
  unordered_map<int, int> freq2;
  for (int i = 0; i < nums1.size(); i++)
  {
   freq1[nums1[i]]++;
  }
  for (int i = 0; i < nums2.size(); i++)
  {
   freq2[nums2[i]]++;
  }
  for (auto i : freq1)
  {
   if (freq2.find(i.first) == freq2.end())
   {
    ans[0].push_back(i.first);
   }
  }
  for (auto i : freq2)
  {
   if (freq1.find(i.first) == freq2.end())
   {
    ans[1].push_back(i.first);
   }
  }
  return ans;
 }
};