#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=u96TGyV73kk

//! Brian Kernighan's algorithm | (Convert 1's to 0's bit by bit)

/*
> Time Complexity: O(num of set bits)
> Space Complexity: O(1)
*/
class Solution
{
public:
 int hammingWeight(uint32_t n)
 {
  //* n & n - 1 => converts rightmost set bit into 0, everything else same
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

//! Check each bit individually

/*
> Time Complexity: O(log n)
> Space Complexity: O()
*/
class Solution
{
public:
 int hammingWeight(uint32_t n)
 {
  int count = 0;
  // we'll check each bit individually
  while (n != 0)
  {
   // check if last bit is 0
   /*
   n     = 1 0 1 0 1/0
   1     = 0 0 0 0 1
   n & 1 = 0 0 0 0 1/0

   So, n & 1 = 1, last digit is 1
             = 0, last digit is 0
   */
   if ((n & 1) == 1)
   {
    count++;
   }

   // do a right shift to remove last digit and get the 2nd last digit
   n >>= 1;
  }
  return count;
 }
};

/*
//> Count no. of trailing zeroes

int count = 0;
//* loop until last digit is zero
while(n % 2 == 0) {
  n = n >> 1; //* n = n / 2;
  count++;
}
*/