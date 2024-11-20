#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Xigsx-FRocs

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

//* we expand our untill the condition is satisfied so that the outer is in turn minimized i.e least amount of mintues required
class Solution
{
public:
  int takeCharacters(string s, int k)
  {
    if (k == 0)
    {
      return 0;
    }

    int n = s.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
      mp[s[i]]++;
    }
    if (mp['a'] < k || mp['b'] < k || mp['c'] < k)
    {
      return -1;
    }

    int l = 0, r = 0;
    int minMinutes = s.size();
    while ((l <= r) && (r < s.size()))
    {
      mp[s[r]]--;

      while ((l <= r) && (mp['a'] < k || mp['b'] < k || mp['c'] < k))
      {
        mp[s[l]]++;
        l++;
      }

      minMinutes = min(minMinutes, n - (r - l + 1));
      r++;
    }
    return minMinutes;
  }
};