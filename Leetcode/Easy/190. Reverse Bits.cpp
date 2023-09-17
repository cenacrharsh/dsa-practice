#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=TC7nCh1MZM8

class Solution
{
public:
 uint32_t reverseBits(uint32_t n)
 {
  /*
  check each bit using it's mask
  n                  = 0 0 0 1 0 1 1
  mask for 1st digit = 1 0 0 0 0 0 0
  & operation        = 0 0 0 0 0 0 0

  So, in mask the concerned digit is 1, rest all are 0
  other 0's ensure all the other bits give 0 on & op.
  but the concerned bit has 1, because we know
  b & 0 = 0
  b & 1 = b
  So if & op gives overall 0 we know concerned bit was also 0, but if it was 1 we'll get a non zero numbers and that is how we check whether each digit is 0 or 1
  */

  uint32_t reverse = 0;
  int j = 0;
  bool firstOneFound = false;

  for (int i = 31; i >= 0; i--)
  {
   int maskForIthBit = (1 << i);

   if ((n & maskForIthBit) != 0)
   {
    // ith bit is 1

    int maskForJthBit = (1 << j);
    reverse |= maskForJthBit;
   }
   j++;
  }
  return reverse;
 }
};