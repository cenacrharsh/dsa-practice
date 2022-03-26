#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=vltY5jxqcco

//! Using Array of Pairs

/*
> Time Complexity: O(123 log 123 + n)
> Space Complexity: O(n)
*/

class Solution
{
public:
 string frequencySort(string s)
 {
  vector<pair<int, char>> hash('z' + 1, {0, 0});
  //* vector of size 123 (z = 122) and filling all array of pairs with default value {0, 0}

  for (auto c : s)
  {
   hash[c] = {hash[c].first + 1, c};
  }

  // sorting in ascending order
  sort(hash.begin(), hash.end());

  string res = "";

  for (auto p : hash)
  {
   res = string(p.first, p.second) + res;
   // since sorted in asc order, we add in front
   // also + is a costly operation of O(l1 + l2), hence we use string(3, a) -> aaa
  }
  return res;
 }
};