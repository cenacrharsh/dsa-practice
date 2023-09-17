#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Set and begin(), rbegin()

int thirdMax(vector<int> &nums)
{
 set<int> top3;
 for (int num : nums)
 {
  top3.insert(num);
  if (top3.size() > 3)
   top3.erase(top3.begin());
 }
 return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}

//! Set and Max Element Func & Next Func

/*
* next() - Get iterator to next element
Returns an iterator pointing to the element that it would be pointing to if advanced n positions.
*/

class Solution
{
public:
 int thirdMax(vector<int> &nums)
 {
  set<int> s(nums.begin(), nums.end());
  return s.size() < 3 ? *max_element(s.begin(), s.end()) : *next(s.begin(), s.size() - 3);
 }
};

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