#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(NLog(N)) + O(MLog(M)) + M
> Space Complexity: O(1)
*/

class Solution
{
public:
  int findContentChildren(vector<int> &greed, vector<int> &sizes)
  {
    sort(greed.begin(), greed.end());
    sort(sizes.begin(), sizes.end());

    int l = 0, r = 0;
    while (l < sizes.size() && r < greed.size())
    {
      //* if we can't satisfy the greed factor of current child with current size of cookie then we inc cookie size
      if (greed[r] <= sizes[l])
      {
        r++;
      }
      l++;
    }
    return r;
  }
};