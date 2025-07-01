#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
  int beautySum(string s)
  {
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
      unordered_map<char, int> mp;
      for (int j = i; j < s.size(); j++)
      {
        mp[s[j]]++;

        //* figure out max & min freq
        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;
        for (auto it : mp)
        {
          maxFreq = max(maxFreq, it.second);
          minFreq = min(minFreq, it.second);
        }
        ans += maxFreq - minFreq;
      }
    }
    return ans;
  }
};