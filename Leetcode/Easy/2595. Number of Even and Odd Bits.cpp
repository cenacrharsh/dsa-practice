#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Bit Manipulation

class Solution
{
public:
 vector<int> evenOddBit(int n)
 {
  int even = 0, odd = 0;
  for (int i = 0; i < 32; i++)
  {
   if (n & (1 << i))
   {
    if (i % 2 == 0)
    {
     even++;
    }
    else
    {
     odd++;
    }
   }
  }
  return {even, odd};
 }
};