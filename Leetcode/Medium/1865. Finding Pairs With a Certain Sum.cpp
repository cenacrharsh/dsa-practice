#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class FindSumPairs
{
public:
 unordered_map<int, int> freq1;
 unordered_map<int, int> freq2;
 vector<int> temp;

 FindSumPairs(vector<int> &nums1, vector<int> &nums2)
 {
  temp = nums2;

  for (int i = 0; i < nums1.size(); i++)
  {
   freq1[nums1[i]]++;
  }

  for (int i = 0; i < nums2.size(); i++)
  {
   freq2[nums2[i]]++;
  }
 }

 void add(int index, int val)
 {
  freq2[temp[index]]--;
  temp[index] += val;
  freq2[temp[index]]++;
 }

 int count(int tot)
 {
  int ans = 0;
  for (auto it = freq1.begin(); it != freq1.end(); it++)
  {
   int a = it->first;
   int b = tot - a;
   if (freq2.count(b))
   {
    ans += it->second * freq2[b];
   }
  }
  return ans;
 }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */