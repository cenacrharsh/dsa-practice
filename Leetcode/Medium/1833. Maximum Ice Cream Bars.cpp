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
 int maxIceCream(vector<int> &costs, int coins)
 {
  int ans = 0;
  int n = costs.size();
  sort(costs.begin(), costs.end());
  for (int i = 0; i < n; i++)
  {
   if (coins >= costs[i])
   {
    ans++;
    coins -= costs[i];
   }
  }
  return ans;
 }
};