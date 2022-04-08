#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Min Priority Queue and Unordered Set

class Solution
{
public:
 int thirdMax(vector<int> &nums)
 {
  unordered_set<int> distinct_nums(nums.begin(), nums.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  int maxNum = INT_MIN;
  for (int i : distinct_nums)
  {
   maxNum = max(i, maxNum);
   pq.push(i);
   if (pq.size() > 3)
   {
    pq.pop();
   }
  }
  if (pq.size() == 3)
  {
   return pq.top();
  }
  else
  {
   return maxNum;
  }
 }
};