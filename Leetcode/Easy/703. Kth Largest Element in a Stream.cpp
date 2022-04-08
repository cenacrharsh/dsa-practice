#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=0tFmP1Eiilg

//! Using Min Priority Queue

class KthLargest
{
public:
 priority_queue<int, vector<int>, greater<int>> pq;
 int size;

 KthLargest(int k, vector<int> &nums)
 {
  size = k;
  for (int i = 0; i < nums.size(); i++)
  {
   pq.push(nums[i]);
   if (pq.size() > k)
   {
    pq.pop();
   }
  }
 }

 int add(int val)
 {
  pq.push(val);
  if (pq.size() > size)
  {
   pq.pop();
  }
  return pq.top();
 }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */