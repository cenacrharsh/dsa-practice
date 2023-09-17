#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Contest Solution

class Solution
{
public:
 int minimumCardPickup(vector<int> &cards)
 {
  unordered_map<int, int> mp;
  int ans = -1;
  int minans = INT_MAX;
  for (int i = 0; i < cards.size(); i++)
  {
   if (mp.find(cards[i]) == mp.end())
   {
    mp[cards[i]] = i;
   }
   else
   {
    int firstOcc = mp[cards[i]];
    ans = i - firstOcc + 1;
    minans = min(ans, minans);
    mp[cards[i]] = i;
   }
  }
  if (minans == INT_MAX)
  {
   return -1;
  }
  return minans;
 }
};