#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=ecI_2MgE6b4

class Solution
{
public:
 bool isUgly(int n)
 {
  //* discard negative numbers
  if (n <= 0)
  {
   return false;
  }

  while (n % 2 == 0)
   n /= 2;
  while (n % 3 == 0)
   n /= 3;
  while (n % 5 == 0)
   n /= 5;

  return n == 1; //* if after all divisions, n is reduced to 1 then it means it can be completely divided using only 2, 3 and 5
 }
};

//# Tutorial: https://www.youtube.com/watch?v=nDPo9hsDNvU&t=555s

/*
! Prime Factorisation using Sieve - won't work here as numbers are very large

* spf[i] -> smallest prime factor of i

while(n != 1)
{
 print spf[n];
 n = n / spf[n];
}
*/

class Solution
{
public:
 bool isUgly(int n)
 {
  vector<int> spf(n + 1);
  for (int i = 2; i <= n; i++)
  {
   spf[i] = i;
  }

  for (int i = 2; i * i <= n; i++)
  {
   if (spf[i] == i)
   {
    for (int j = i * i; j <= n; j += i)
    {
     // if spf[j] already marked then it has it's spf set already
     if (spf[j] == j)
     {
      spf[j] = i;
     }
    }
   }
  }

  while (n != 1)
  {
   // even if no prime factors like in case of 1 we return true, only if a prime factor other than these 3 occurs we return false
   if (spf[n] != 2 && spf[n] != 3 && spf[n] != 5)
   {
    return false;
   }
   n = n / spf[n];
  }

  return true;
 }
};