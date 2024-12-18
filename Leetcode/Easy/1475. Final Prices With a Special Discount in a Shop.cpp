#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    stack<int> st;
    vector<int> ans(prices.size(), 0);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
      //* we want <= our current price on top of our stack
      while (!st.empty() && st.top() > prices[i])
      {
        st.pop();
      }

      if (!st.empty())
      {
        ans[i] = prices[i] - st.top();
      }
      else
      {
        ans[i] = prices[i];
      }

      st.push(prices[i]);
    }
    return ans;
  }
};