#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Bitwise Operator ^

class Solution
{
public:
 int singleNumber(vector<int> &nums)
 {
  int unique = 0;
  for (int n : nums)
  {
   unique ^= n;
  }
  return unique;
 }
};