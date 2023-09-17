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
 int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
 {
  int n = capacity.size();
  vector<int> left(n, 0);
  for (int i = 0; i < n; i++)
  {
   left[i] = capacity[i] - rocks[i];
  }
  sort(left.begin(), left.end());
  int ans = 0;
  int i = 0;
  while (additionalRocks != 0 && i < n)
  {
   if (left[i] == 0)
   {
    ans++;
   }
   else
   {
    if (left[i] <= additionalRocks)
    {
     ans++;
     additionalRocks -= left[i];
    }
   }
   i++;
  }
  return ans;
 }
};