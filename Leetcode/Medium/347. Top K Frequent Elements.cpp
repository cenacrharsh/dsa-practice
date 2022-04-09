#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Unordered Map & Min Priority Queue

/*
> Time Complexity: O(n * log k)
> Space Complexity: O(n)
*/

class Solution
{
public:
 vector<int> topKFrequent(vector<int> &nums, int k)
 {
  unordered_map<int, int> freq;
  for (int i = 0; i < nums.size(); i++)
  {
   freq[nums[i]]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> ans;
  for (auto n : freq)
  {
   int num = n.first;
   int num_freq = n.second;
   pq.push(make_pair(num_freq, num));
   if (pq.size() > k)
   {
    pq.pop();
   }
  }
  while (pq.size() != 0)
  {
   int num = (pq.top()).second;
   ans.push_back(num);
   pq.pop();
  }
  return ans;
 }
};