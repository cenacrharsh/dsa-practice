#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=I80Ovvi_nRU

//! Bit Manipulation
class Solution
{
public:
 bool isPowerOfTwo(int n)
 {
  // 1 << x = 2^x = 1 000..(x o's from 2^0 -> 2^x-1 and 1 is the 2^xth one)
  // n << x = n * 2^x ( i.e multiply the num with 2^x)
  // n >> x = n / 2^x ( i.e divide the num by 2^x)

  // n       = 1 000
  // n-1     = 0 111
  // n & n-1 = 0 000, so if n & n - 1 is 0, n is power of 2

  if (n <= 0)
  {
   return false;
  }
  return (n & n - 1) == 0;
 }
};

//! By generating powers and checking
class Solution
{
public:
 bool isPowerOfTwo(int n)
 {
  long powersOfTwo = 1; // we start with the first one 2^0 = 1

  // we keep generating powers of 2 until it's < n
  while (powersOfTwo < n)
  {
   powersOfTwo *= 2;
  }

  // check if i == n, if not we can't generate any more powers as it'll cross n
  return powersOfTwo == n;
 }
};