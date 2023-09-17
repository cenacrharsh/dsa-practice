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
 int lastStoneWeight(vector<int> &stones)
 {
  // priority_queue<int> pq(stones.begin(), stones.end());
  priority_queue<int> pq;
  for (int weight : stones)
  {
   pq.push(weight);
  }
  while (pq.size() > 1)
  {
   int y = pq.top();
   pq.pop();
   int x = pq.top();
   pq.pop();

   if (x == y)
   {
    continue;
   }
   else
   {
    pq.push(y - x);
   }
  }
  return pq.empty() ? 0 : pq.top();
 }
};