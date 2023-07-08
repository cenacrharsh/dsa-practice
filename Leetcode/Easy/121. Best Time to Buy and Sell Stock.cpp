// # Tutorial: https://www.youtube.com/watch?v=4YjEHmw1MX0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=30

//! One Transaction Allowed

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//! Left -> Right
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minSellingPrice = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            minSellingPrice = min(minSellingPrice, prices[i]);
            int tempProfit = prices[i] - minSellingPrice;
            maxProfit = max(maxProfit, tempProfit);
        }
        return maxProfit;
    }
};

//! Right -> Left
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxSellingPrice = INT_MIN;
        int profit = 0;
        int maxProfit = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            maxSellingPrice = max(maxSellingPrice, prices[i]);
            profit = maxSellingPrice - prices[i];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};