#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Approach
int bulbSwitch(int n)
{
 return (int)sqrt(n);
}

//! Brute Force Approach
int toggleTheBulb(int n)
{
 bool bulb[n + 1] = {0};
 for (int i = 1; i <= n; i++)
 {
  for (int j = i; j <= n; j += i)
  {
   bulb[j] = !bulb[j];
  }
 }

 int count = 0;
 for (int i = 1; i <= n; i++)
 {
  if (bulb[i] == 1)
  {
   count++;
  }
 }

 return count;
}