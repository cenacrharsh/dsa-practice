#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=EKmUgWZXPMs

//! Bit Manipulation
class Solution
{
public:
 int hammingWeight(uint32_t n)
 {
  //* n & n - 1 => converts rightmost set bit and everything after it into 0
  /*
  x         = 11100 1 00
  x - 1     = 11100 0 11 (flips rightmost set bit & all 0's after it)
  x & x - 1 = 11100 0 00

  so basically x & x - 1 removes one set bit from number x
  */

  int numOfSetBits = 0;
  while (n != 0)
  {
   n = n & n - 1;
   numOfSetBits++;
  }
  return numOfSetBits;
 }
};