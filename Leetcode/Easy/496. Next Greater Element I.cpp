#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=8BDKB2yuGyg

class Solution
{
public:
 vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
 {
  unordered_map<int, int> map;
  stack<int> st;
  st.push(nums2[0]);
  for (int i = 1; i < nums2.size(); i++)
  {
   if (!st.empty() && nums2[i] > st.top())
   {
    while (!st.empty() && nums2[i] > st.top())
    {
     map[st.top()] = nums2[i];
     st.pop();
    }
   }
   st.push(nums2[i]);
  }
  for (int i = 0; i < nums1.size(); i++)
  {
   if (map.find(nums1[i]) != map.end())
   {
    nums1[i] = map[nums1[i]];
   }
   else
   {
    nums1[i] = -1;
   }
  }
  return nums1;
 }
};

class Solution
{
public:
 vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
 {
  unordered_map<int, int> map;
  stack<int> st;
  st.push(nums2[0]);
  for (int i = 1; i < nums2.size(); i++)
  {
   if (!st.empty() && nums2[i] > st.top())
   {
    while (!st.empty() && nums2[i] > st.top())
    {
     map[st.top()] = nums2[i];
     st.pop();
    }
   }
   st.push(nums2[i]);
  }
  while (!st.empty())
  {
   map[st.top()] = -1;
   st.pop();
  }
  vector<int> ans;
  for (int i = 0; i < nums1.size(); i++)
  {
   ans.push_back(map[nums1[i]]);
  }
  return ans;
 }
};