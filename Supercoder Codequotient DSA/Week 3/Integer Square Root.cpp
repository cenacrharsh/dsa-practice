#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int sqrt(long n)
{
 if (n == 0)
 {
  return 0;
 }
 long low = 1;
 long high = n;
 long sqRoot;
 while (low <= high)
 {
  long mid = low + (high - low) / 2;
  if (mid <= n / mid)
  {
   low = mid + 1;
   sqRoot = mid;
  }
  else
  {
   high = mid - 1;
  }
 }
 return sqRoot;
}