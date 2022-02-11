#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxProfit(vector<int> prices)
{
 // Write your code here
 int maxProfit = 0, minPrice = prices[0];

 for (int i = 1; i < prices.size(); i++)
 {
  int tempProfit = prices[i] - minPrice;
  maxProfit = max(maxProfit, tempProfit);

  minPrice = min(minPrice, prices[i]);
 }

 return maxProfit;
}