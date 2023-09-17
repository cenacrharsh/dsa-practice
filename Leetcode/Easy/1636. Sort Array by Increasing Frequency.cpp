#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=PjKjbpI2Z3s

//! Using Lambda Func in Sort Func

//> Lamda Func: [&] (parameters) { return Expresssion }

class Solution
{
public:
 vector<int> frequencySort(vector<int> &nums)
 {
  unordered_map<int, int> freq;
  for (auto i : nums)
  {
   freq[i]++;
  }

  //* using lambda func
  sort(nums.begin(), nums.end(), [&](int a, int b)
       { return (freq[a] != freq[b] ? freq[a] < freq[b] : a > b); });

  return nums;
 }
};

//# Tutorial: https://www.youtube.com/watch?v=S6UvwcpVnxc

//! Using Hashmap & Vector of Vector

class Solution
{
public:
 static bool comparator(vector<int> a, vector<int> b)
 {
  if (a[0] != b[0])
  {
   return a[0] < b[0]; //* ele with less freq before, i.e. asc order
  }
  else
  {
   return a[1] > b[1]; //* if freq same then ele with larger value before, i.e. des order
  }
 }
 vector<int> frequencySort(vector<int> &nums)
 {
  unordered_map<int, int> freq;
  for (auto i : nums)
  {
   freq[i]++;
  }
  vector<vector<int>> v;
  for (auto i : freq)
  {
   v.push_back({i.second, i.first}); //* freq -> element
  }
  //* sort
  sort(v.begin(), v.end(), comparator);
  vector<int> ans;
  for (auto i : v)
  {
   int count = i[0];
   while (count--)
   {
    ans.push_back(i[1]);
   }
  }
  return ans;
 }
};

/*

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> freq(n, {0, 0}); // freq -> element
        for(auto i : nums)
        {
            cout << freq[i].first << " freq is; " << freq[i].second << endl;
        }
        for(auto i : freq)
        {
            cout << i.first << " freq is: " << i.second << endl;
        }
        vector<int> ans(n);
        return ans;
    }
};

*/