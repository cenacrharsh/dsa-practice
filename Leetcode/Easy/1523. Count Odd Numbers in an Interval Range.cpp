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

/*
Let's start with an odd integer, say x; what would be the next odd integer? It would be x + 2; as explained above, there is exactly one even integer between every two odd integers, and hence all odd integers are equally spaced with a gap of one integer. By trying out some examples, we can deduce that the count of odd integers between x and a greater integer y where x is odd would be (y-x)/2 + 1
*/

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

//! Bit Manipulation
class Solution
{
public:
 int countOdds(int low, int high)
 {
  int count = 0;
  for (int i = low; i <= high; i++)
  {
   // i & 1 = 1, tells last bit is 1 i.e. odd
   if (i & 1 == 1)
   {
    count++;
   }
  }
  return count;
 }
};