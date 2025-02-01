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
  bool isArraySpecial(vector<int> &nums)
  {
    vector<int> parity(nums.size(), -1); // 1 for odd, 0 for even
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] % 2 == 0)
      {
        parity[i] = 0;
      }
      else
      {
        parity[i] = 1;
      }
    }

    bool ans = true;
    for (int i = 1; i < parity.size(); i++)
    {
      if (parity[i] == parity[i - 1])
      {
        ans = false;
        break;
      }
    }
    return ans;
  }
};