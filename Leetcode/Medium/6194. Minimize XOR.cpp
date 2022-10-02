#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 int minimizeXor(int num1, int num2)
 {
  int setbitsinb = __builtin_popcount(num2);
  int setbitsina = __builtin_popcount(num1);
  int ans = 0;
  for (int i = 0; i <= 31; i++)
  {
   int mask = 1 << i;
   int set = num1 & mask;
   if (set == 0 && setbitsinb > setbitsina)
   {
    ans |= (mask);
    setbitsinb--;
   }
   else if (set && setbitsina > setbitsinb)
    setbitsina--;
   else
    ans |= set;
  }
  return ans;
 }
};