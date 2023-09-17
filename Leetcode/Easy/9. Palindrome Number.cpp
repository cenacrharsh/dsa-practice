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
 bool isPalindrome(int x)
 {
  if (x < 0)
  {
   return false;
  }
  int original = x;
  long long int num = 0;
  while (x > 0)
  {
   long long int temp = x % 10;
   num = (num * 10) + temp;
   x = x / 10;
  }
  if (original == num)
  {
   return true;
  }
  else
  {
   return false;
  }
 }
};