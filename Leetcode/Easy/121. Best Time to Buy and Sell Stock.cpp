#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
 int maxProfit(vector<int> &prices)
 {
  int minPrice = prices[0];
  int maxProfit = 0;
  for (int i = 1; i < prices.size(); i++)
  {
   int tempProfit = prices[i] - minPrice;
   maxProfit = max(maxProfit, tempProfit);
   minPrice = min(minPrice, prices[i]);
  }
  return maxProfit;
 }
};