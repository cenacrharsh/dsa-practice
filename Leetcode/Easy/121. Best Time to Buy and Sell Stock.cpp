#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=excAOvwF_Wk&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=17

//- if you are selling on iTh day, you want to buy the stock in minimum price form [1...i - 1] day

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
            int tempProfit = prices[i] - minSellingPrice;
            maxProfit = max(maxProfit, tempProfit);
            minSellingPrice = min(minSellingPrice, prices[i]);
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