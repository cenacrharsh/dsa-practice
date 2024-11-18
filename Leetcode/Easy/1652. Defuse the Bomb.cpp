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
  vector<int> decrypt(vector<int> &code, int k)
  {
    int n = code.size();
    vector<int> ans(n, 0);
    if (k == 0)
    {
      return ans;
    }
    else if (k > 0)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 1; j <= k; j++)
        {
          ans[i] += code[(i + j) % n];
        }
      }
    }
    else if (k < 0)
    {
      k = k * (-1);
      for (int i = 0; i < n; i++)
      {
        for (int j = 1; j <= k; j++)
        {
          ans[i] += code[(n + (i - j)) % n];
        }
      }
    }
    return ans;
  }
};