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
 int reverse(int x)
 {
  int ans = 0;
  int temp = x;
  while (temp != 0)
  {
   if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
   {
    return 0;
   }
   else
   {
    int lastDigit = temp % 10;
    ans = ans * 10 + lastDigit;
    temp = temp / 10;
   }
  }
  return ans;
 }
};