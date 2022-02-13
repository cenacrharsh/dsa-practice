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
  int buyingDate = 0;
  int sellingDate = 0;
  int totalProfit = 0;
  for (int i = 1; i < prices.size(); i++)
  {
   if (prices[i] >= prices[i - 1])
   {
    sellingDate++;
   }
   else
   {
    totalProfit += prices[sellingDate] - prices[buyingDate];
    buyingDate = i;
    sellingDate = i;
   }
  }
  // last transaction won't be done if no dip in price. so handle it separately
  totalProfit += prices[sellingDate] - prices[buyingDate];
  return totalProfit;
 }
};