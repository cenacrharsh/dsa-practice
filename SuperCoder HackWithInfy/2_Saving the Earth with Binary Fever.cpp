#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimized Approach
int getMinJumps(unsigned long long int n)
{
 int count = 0;
 while (n != 0)
 {
  n = n & n - 1;
  count++;
 }
 return count;
}

//! Brute Force Approach
int getMinJumps(unsigned long long int n)
{
 unsigned long long int count = 0;
 unsigned long long int remainingDist = n;

 while (remainingDist > 0)
 {
  unsigned long long int x = 0;
  for (unsigned long long int i = 0; pow(2, i) <= remainingDist; i++)
  {
   x = pow(2, i);
  }
  remainingDist -= x;
  count++;
 }
 return count;
}