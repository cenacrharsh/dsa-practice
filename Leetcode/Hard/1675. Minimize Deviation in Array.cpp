#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=CP7M1JrBoc8

class Solution
{
public:
 int minimumDeviation(vector<int> &nums)
 {
  priority_queue<int> pq;
  int minElement = INT_MAX;
  for (auto i : nums)
  {
   if (i % 2 == 0)
   {
    pq.push(i);
    minElement = min(minElement, i);
   }
   else
   {
    pq.push(i * 2); // to get all evens
    minElement = min(minElement, i * 2);
   }
  }

  int ans = INT_MAX;
  while (!pq.empty())
  {
   int top = pq.top();
   pq.pop();

   ans = min(ans, top - minElement);

   if (top % 2 != 0)
   {
    break;
   }

   minElement = min(minElement, top / 2);
   pq.push(top / 2);
  }
  return ans;
 }
};