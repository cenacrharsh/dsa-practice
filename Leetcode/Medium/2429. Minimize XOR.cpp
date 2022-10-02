#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=KdV20LgRT70
class Solution
{
public:
  int minimizeXor(int num1, int num2)
  {
    // calc num of set bits in num2
    int countsetbitsinnum2 = 0;
    int temp = num2;
    while (temp)
    {
      countsetbitsinnum2 += temp % 2;
      temp /= 2;
    }
    int ans = 0;
    int bitstosetinans = countsetbitsinnum2;

    // set bits in ans from right to left aq num1 set bits to minimize value of ans
    for (int i = 31; i >= 0 && bitstosetinans; i--)
    {
      if (num1 & (1 << i)) // check if bit is set in num1
      {
        ans |= (1 << i); // set bit in ans at that pos aq num1
        bitstosetinans--;
      }
    }

    // if set bits left to set in ans, do so from left to right to get min value
    for (int i = 0; i <= 31 && bitstosetinans; i++)
    {
      if ((ans & (1 << i)) == 0)
      {
        ans |= (1 << i);
        bitstosetinans--;
      }
    }
    return ans;
  }
};

//! Contest Solution
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