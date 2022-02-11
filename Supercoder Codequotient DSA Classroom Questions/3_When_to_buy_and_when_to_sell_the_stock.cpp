#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
> Time Complexity: O(n2)
> Space Complexity: O(1)
*/

int findMaxProfit(int price[], int n)
{
 int maxProfit = 0;

 for (int i = 0; i < n; i++)
 {
  for (int j = i + 1; j < n; j++)
  {
   int tempProfit = price[j] - price[i];
   maxProfit = max(maxProfit, tempProfit);
  }
 }
 return maxProfit;
}

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

int findMaxProfit2(int price[], int n)
{
 //> maxProfit is 0 if we buy and sell on the same day
 int maxProfit = 0, minPrice = price[0];

 for (int i = 1; i < n; i++)
 {
  int tempProfit = price[i] - minPrice;
  maxProfit = max(maxProfit, tempProfit);

  minPrice = min(minPrice, price[i]);
 }

 return maxProfit;
}