#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
x & 1 is equivalent to x % 2
x >> 1 is equivalent to x / 2
x << 1 is equivalent to x * 2
*/

//! either both odd, or either one is odd in both cases h - l / 2 + 1 is the answer, so in case both even we increment and make it odd so we can use the same formula

class Solution
{
public:
 int countOdds(int low, int high)
 {
  // If low is even, make it odd
  if ((low & 1) == 0)
  {
   low++;
  }

  // low could become greater than high due to incrementation
  // if it is, the answer is 0; otherwise, use the formula
  return low > high ? 0 : (((high - low) / 2) + 1);
 }
};